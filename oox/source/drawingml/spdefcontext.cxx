/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#include "oox/drawingml/spdefcontext.hxx"
#include "oox/drawingml/shapepropertiescontext.hxx"
#include "oox/drawingml/textbody.hxx"
#include "oox/drawingml/textbodypropertiescontext.hxx"
#include "oox/drawingml/textliststylecontext.hxx"

using rtl::OUString;
using namespace ::oox::core;
using namespace ::com::sun::star::uno;
using namespace ::com::sun::star::xml::sax;

namespace oox { namespace drawingml {

spDefContext::spDefContext( ContextHandler& rParent, Shape& rDefaultObject )
: ContextHandler( rParent )
, mrDefaultObject( rDefaultObject )
{
}

Reference< XFastContextHandler > spDefContext::createFastChildContext( sal_Int32 aElementToken, const Reference< XFastAttributeList >& xAttribs ) throw (SAXException, RuntimeException)
{
	Reference< XFastContextHandler > xRet;
	switch( aElementToken )
	{
		case A_TOKEN( spPr ):
		{
            xRet = new ShapePropertiesContext( *this, mrDefaultObject );
			break;
		}
		case A_TOKEN( bodyPr ):
		{
            TextBodyPtr xTextBody( new TextBody );
            mrDefaultObject.setTextBody( xTextBody );
            xRet = new TextBodyPropertiesContext( *this, xAttribs, xTextBody->getTextProperties() );
			break;
		}
		case A_TOKEN( lstStyle ):
            xRet.set( new TextListStyleContext( *this, *mrDefaultObject.getMasterTextListStyle() ) );
			break;
		case A_TOKEN( style ):
			break;
	}
	if( !xRet.is() )
		xRet.set( this );

	return xRet;
}

} }

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



#include <stdio.h>
#include <osl/diagnose.h>
#include "SPreparedStatement.hxx"
#include <com/sun/star/sdbc/DataType.hpp>
#include "SResultSetMetaData.hxx"
#include <cppuhelper/typeprovider.hxx>
#include <com/sun/star/lang/DisposedException.hpp>
#include "propertyids.hxx"

using namespace connectivity::skeleton;
using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::beans;
using namespace com::sun::star::sdbc;
using namespace com::sun::star::container;
using namespace com::sun::star::io;
using namespace com::sun::star::util;

IMPLEMENT_SERVICE_INFO(OPreparedStatement,"com.sun.star.sdbcx.skeleton.PreparedStatement","com.sun.star.sdbc.PreparedStatement");


OPreparedStatement::OPreparedStatement( OConnection* _pConnection,const TTypeInfoVector& _TypeInfo,const ::rtl::OUString& sql)
	:OStatement_BASE2(_pConnection)
	,m_aTypeInfo(_TypeInfo)
	,m_bPrepared(sal_False)
	,m_sSqlStatement(sql)
	,m_nNumParams(0)
{
}
// -----------------------------------------------------------------------------
OPreparedStatement::~OPreparedStatement()
{
}
// -----------------------------------------------------------------------------
void SAL_CALL OPreparedStatement::acquire() throw()
{
	OStatement_BASE2::acquire();
}
// -----------------------------------------------------------------------------
void SAL_CALL OPreparedStatement::release() throw()
{
	OStatement_BASE2::release();
}
// -----------------------------------------------------------------------------
Any SAL_CALL OPreparedStatement::queryInterface( const Type & rType ) throw(RuntimeException)
{
	Any aRet = OStatement_BASE2::queryInterface(rType);
	if(!aRet.hasValue())
		aRet = OPreparedStatement_BASE::queryInterface(rType);
	return aRet;
}
// -------------------------------------------------------------------------
::com::sun::star::uno::Sequence< ::com::sun::star::uno::Type > SAL_CALL OPreparedStatement::getTypes(  ) throw(::com::sun::star::uno::RuntimeException)
{
	return concatSequences(OPreparedStatement_BASE::getTypes(),OStatement_BASE2::getTypes());
}
// -------------------------------------------------------------------------

Reference< XResultSetMetaData > SAL_CALL OPreparedStatement::getMetaData(  ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
	if(!m_xMetaData.is())
		m_xMetaData = new OResultSetMetaData(getOwnConnection());
	return m_xMetaData;
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::close(  ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		

	// Reset last warning message

	try {
		clearWarnings ();
		OStatement_BASE2::close();
	}
	catch (SQLException &) {
		// If we get an error, ignore
	}

	// Remove this Statement object from the Connection object's
	// list
}
// -------------------------------------------------------------------------

sal_Bool SAL_CALL OPreparedStatement::execute(  ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		

	// same as in statement with the difference that this statement also can contain parameter
	return sal_False;
}
// -------------------------------------------------------------------------

sal_Int32 SAL_CALL OPreparedStatement::executeUpdate(  ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
	// same as in statement with the difference that this statement also can contain parameter
	return 0;
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setString( sal_Int32 parameterIndex, const ::rtl::OUString& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
}
// -------------------------------------------------------------------------

Reference< XConnection > SAL_CALL OPreparedStatement::getConnection(  ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
	return (Reference< XConnection >)m_pConnection;
}
// -------------------------------------------------------------------------

Reference< XResultSet > SAL_CALL OPreparedStatement::executeQuery(  ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
	Reference< XResultSet > rs = NULL;

	
	return rs;
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setBoolean( sal_Int32 parameterIndex, sal_Bool x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------
void SAL_CALL OPreparedStatement::setByte( sal_Int32 parameterIndex, sal_Int8 x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		

}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setDate( sal_Int32 parameterIndex, const Date& aData ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------


void SAL_CALL OPreparedStatement::setTime( sal_Int32 parameterIndex, const Time& aVal ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setTimestamp( sal_Int32 parameterIndex, const DateTime& aVal ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setDouble( sal_Int32 parameterIndex, double x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}

// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setFloat( sal_Int32 parameterIndex, float x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setInt( sal_Int32 parameterIndex, sal_Int32 x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setLong( sal_Int32 parameterIndex, sal_Int64 aVal ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setNull( sal_Int32 parameterIndex, sal_Int32 sqlType ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setClob( sal_Int32 parameterIndex, const Reference< XClob >& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setBlob( sal_Int32 parameterIndex, const Reference< XBlob >& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setArray( sal_Int32 parameterIndex, const Reference< XArray >& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setRef( sal_Int32 parameterIndex, const Reference< XRef >& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setObjectWithInfo( sal_Int32 parameterIndex, const Any& x, sal_Int32 sqlType, sal_Int32 scale ) throw(SQLException, RuntimeException)
{
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
	::osl::MutexGuard aGuard( m_aMutex );	

}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setObjectNull( sal_Int32 parameterIndex, sal_Int32 sqlType, const ::rtl::OUString& typeName ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setObject( sal_Int32 parameterIndex, const Any& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setShort( sal_Int32 parameterIndex, sal_Int16 x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setBytes( sal_Int32 parameterIndex, const Sequence< sal_Int8 >& x ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------


void SAL_CALL OPreparedStatement::setCharacterStream( sal_Int32 parameterIndex, const Reference< ::com::sun::star::io::XInputStream >& x, sal_Int32 length ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::setBinaryStream( sal_Int32 parameterIndex, const Reference< ::com::sun::star::io::XInputStream >& x, sal_Int32 length ) throw(SQLException, RuntimeException)
{
	::osl::MutexGuard aGuard( m_aMutex );
	checkDisposed(OStatement_BASE::rBHelper.bDisposed);
		
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::clearParameters(  ) throw(SQLException, RuntimeException)
{
}
// -------------------------------------------------------------------------
void SAL_CALL OPreparedStatement::clearBatch(  ) throw(SQLException, RuntimeException)
{
}
// -------------------------------------------------------------------------

void SAL_CALL OPreparedStatement::addBatch( ) throw(SQLException, RuntimeException)
{
}
// -------------------------------------------------------------------------

Sequence< sal_Int32 > SAL_CALL OPreparedStatement::executeBatch(  ) throw(SQLException, RuntimeException)
{
	return Sequence< sal_Int32 > ();
}
// -------------------------------------------------------------------------
void OPreparedStatement::setFastPropertyValue_NoBroadcast(sal_Int32 nHandle,const Any& rValue) throw (Exception)
{
	switch(nHandle)
	{
		case PROPERTY_ID_RESULTSETCONCURRENCY:
			break;
		case PROPERTY_ID_RESULTSETTYPE:
			break;
		case PROPERTY_ID_FETCHDIRECTION:
			break;
		case PROPERTY_ID_USEBOOKMARKS:
			break;
		default:
			OStatement_Base::setFastPropertyValue_NoBroadcast(nHandle,rValue);
	}
}
// -----------------------------------------------------------------------------
void OPreparedStatement::checkParameterIndex(sal_Int32 _parameterIndex)
{
	if(	!_parameterIndex || _parameterIndex > m_nNumParams)
		throw SQLException();
}
// -----------------------------------------------------------------------------



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



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_sal.hxx"

#include "rtl/strbuf.hxx"
#include "rtl/textenc.h"
#include "rtl/uri.h"
#include "rtl/uri.hxx"
#include "rtl/ustrbuf.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#include <cstddef>
#include <stdio.h>
#include "gtest/gtest.h"

namespace {

class Test: public ::testing::Test {
public:
};

TEST_F(Test, test_Uri) {
    rtl_UriCharClass const eFirstCharClass = rtl_UriCharClassNone;
    rtl_UriCharClass const eLastCharClass = rtl_UriCharClassUnoParamValue;

    rtl::OUStringBuffer aBuffer;
    rtl::OUString aText1;
    rtl::OUString aText2;

    // Check that all characters map back to themselves when encoded/decoded:

    aText1 = rtl::OUString(
        RTL_CONSTASCII_USTRINGPARAM(
            "\0x00\0x01\0x02\0x03\0x04\0x05\0x06\0x07"
            "\0x08\0x09\0x0A\0x0B\0x0C\0x0D\0x0E\0x0F"
            "\0x10\0x11\0x12\0x13\0x14\0x15\0x16\0x17"
            "\0x18\0x19\0x1A\0x1B\0x1C\0x1D\0x1E\0x1F"
            "\0x20\0x21\0x22\0x23\0x24\0x25\0x26\0x27"
            "\0x28\0x29\0x2A\0x2B\0x2C\0x2D\0x2E\0x2F"
            "\0x30\0x31\0x32\0x33\0x34\0x35\0x36\0x37"
            "\0x38\0x39\0x3A\0x3B\0x3C\0x3D\0x3E\0x3F"
            "\0x40\0x41\0x42\0x43\0x44\0x45\0x46\0x47"
            "\0x48\0x49\0x4A\0x4B\0x4C\0x4D\0x4E\0x4F"
            "\0x50\0x51\0x52\0x53\0x54\0x55\0x56\0x57"
            "\0x58\0x59\0x5A\0x5B\0x5C\0x5D\0x5E\0x5F"
            "\0x60\0x61\0x62\0x63\0x64\0x65\0x66\0x67"
            "\0x68\0x69\0x6A\0x6B\0x6C\0x6D\0x6E\0x6F"
            "\0x70\0x71\0x72\0x73\0x74\0x75\0x76\0x77"
            "\0x78\0x79\0x7A\0x7B\0x7C\0x7D\0x7E\0x7F"));
    aText2 = aText1;
    {for (rtl_UriCharClass eCharClass = eFirstCharClass;
          eCharClass <= eLastCharClass;
          eCharClass = static_cast< rtl_UriCharClass >(eCharClass + 1))
    {
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeKeepEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ASCII_US)
             == aText2)) << 
            "failure 1";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeCheckEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ASCII_US)
             == aText2)) << 
            "failure 2";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeKeepEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ISO_8859_1)
             == aText2)) << 
            "failure 3";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeCheckEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ISO_8859_1)
             == aText2)) << 
            "failure 4";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeKeepEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 5";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeCheckEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 6";
    }}

    aText1 = rtl::OUString(
        RTL_CONSTASCII_USTRINGPARAM(
            "\0x00\0x01\0x02\0x03\0x04\0x05\0x06\0x07"
            "\0x08\0x09\0x0A\0x0B\0x0C\0x0D\0x0E\0x0F"
            "\0x10\0x11\0x12\0x13\0x14\0x15\0x16\0x17"
            "\0x18\0x19\0x1A\0x1B\0x1C\0x1D\0x1E\0x1F"
            "\0x20\0x21\0x22\0x23\0x24\0x25\0x26\0x27"
            "\0x28\0x29\0x2A\0x2B\0x2C\0x2D\0x2E\0x2F"
            "\0x30\0x31\0x32\0x33\0x34\0x35\0x36\0x37"
            "\0x38\0x39\0x3A\0x3B\0x3C\0x3D\0x3E\0x3F"
            "\0x40\0x41\0x42\0x43\0x44\0x45\0x46\0x47"
            "\0x48\0x49\0x4A\0x4B\0x4C\0x4D\0x4E\0x4F"
            "\0x50\0x51\0x52\0x53\0x54\0x55\0x56\0x57"
            "\0x58\0x59\0x5A\0x5B\0x5C\0x5D\0x5E\0x5F"
            "\0x60\0x61\0x62\0x63\0x64\0x65\0x66\0x67"
            "\0x68\0x69\0x6A\0x6B\0x6C\0x6D\0x6E\0x6F"
            "\0x70\0x71\0x72\0x73\0x74\0x75\0x76\0x77"
            "\0x78\0x79\0x7A\0x7B\0x7C\0x7D\0x7E\0x7F"
            "\0x80\0x81\0x82\0x83\0x84\0x85\0x86\0x87"
            "\0x88\0x89\0x8A\0x8B\0x8C\0x8D\0x8E\0x8F"
            "\0x90\0x91\0x92\0x93\0x94\0x95\0x96\0x97"
            "\0x98\0x99\0x9A\0x9B\0x9C\0x9D\0x9E\0x9F"
            "\0xA0\0xA1\0xA2\0xA3\0xA4\0xA5\0xA6\0xA7"
            "\0xA8\0xA9\0xAA\0xAB\0xAC\0xAD\0xAE\0xAF"
            "\0xB0\0xB1\0xB2\0xB3\0xB4\0xB5\0xB6\0xB7"
            "\0xB8\0xB9\0xBA\0xBB\0xBC\0xBD\0xBE\0xBF"
            "\0xC0\0xC1\0xC2\0xC3\0xC4\0xC5\0xC6\0xC7"
            "\0xC8\0xC9\0xCA\0xCB\0xCC\0xCD\0xCE\0xCF"
            "\0xD0\0xD1\0xD2\0xD3\0xD4\0xD5\0xD6\0xD7"
            "\0xD8\0xD9\0xDA\0xDB\0xDC\0xDD\0xDE\0xDF"
            "\0xE0\0xE1\0xE2\0xE3\0xE4\0xE5\0xE6\0xE7"
            "\0xE8\0xE9\0xEA\0xEB\0xEC\0xED\0xEE\0xEF"
            "\0xF0\0xF1\0xF2\0xF3\0xF4\0xF5\0xF6\0xF7"
            "\0xF8\0xF9\0xFA\0xFB\0xFC\0xFD\0xFE\0xFF"));
    aText2 = aText1;
    {for (rtl_UriCharClass eCharClass = eFirstCharClass;
          eCharClass <= eLastCharClass;
          eCharClass = static_cast< rtl_UriCharClass >(eCharClass + 1))
    {
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeKeepEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ISO_8859_1)
             == aText2)) << 
            "failure 7";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeCheckEscapes,
                    RTL_TEXTENCODING_ISO_8859_1),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ISO_8859_1)
             == aText2)) << 
            "failure 8";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeKeepEscapes,
                    RTL_TEXTENCODING_UTF8),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 9";
        ASSERT_TRUE((rtl::Uri::decode(
                rtl::Uri::encode(
                    aText1, eCharClass, rtl_UriEncodeCheckEscapes,
                    RTL_TEXTENCODING_UTF8),
                rtl_UriDecodeWithCharset, RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 10";
    }}

    // Check surrogate handling:

    aBuffer.append(static_cast< sal_Unicode >(0xD800)); // %ED%A0%80
    aBuffer.append(static_cast< sal_Unicode >(0xD800)); // %F0%90%8F%BF
    aBuffer.append(static_cast< sal_Unicode >(0xDFFF));
    aBuffer.append(static_cast< sal_Unicode >(0xDFFF)); // %ED%BF%BF
    aBuffer.append(static_cast< sal_Unicode >('A')); // A
    aText1 = aBuffer.makeStringAndClear();
    aText2 = rtl::OUString(
        RTL_CONSTASCII_USTRINGPARAM(
            "%ED%A0%80" "%F0%90%8F%BF" "%ED%BF%BF" "A"));
    ASSERT_TRUE((rtl::Uri::encode(
            aText1, rtl_UriCharClassUric, rtl_UriEncodeIgnoreEscapes,
            RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 11";
    ASSERT_TRUE((rtl::Uri::encode(
            aText1, rtl_UriCharClassUric, rtl_UriEncodeKeepEscapes,
            RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 12";
    ASSERT_TRUE((rtl::Uri::encode(
            aText1, rtl_UriCharClassUric, rtl_UriEncodeCheckEscapes,
            RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 13";

    aText1 = rtl::OUString(
        RTL_CONSTASCII_USTRINGPARAM(
            "%ed%a0%80" "%f0%90%8f%bf" "%ed%bf%bf" "A"));
    aBuffer.appendAscii(RTL_CONSTASCII_STRINGPARAM("%ED%A0%80"));
    aBuffer.append(static_cast< sal_Unicode >(0xD800));
    aBuffer.append(static_cast< sal_Unicode >(0xDFFF));
    aBuffer.appendAscii(RTL_CONSTASCII_STRINGPARAM("%ED%BF%BF"));
    aBuffer.append(static_cast< sal_Unicode >('A'));
    aText2 = aBuffer.makeStringAndClear();
    ASSERT_TRUE((rtl::Uri::decode(aText1, rtl_UriDecodeToIuri, RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 14";
    ASSERT_TRUE((rtl::Uri::decode(
            aText1, rtl_UriDecodeWithCharset, RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 15";

    // Check UTF-8 handling:

    aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%E0%83%BF"));
        // \U+00FF encoded with three instead of two bytes
    aText2 = aText1;
    ASSERT_TRUE((rtl::Uri::encode(
            aText1, rtl_UriCharClassUric, rtl_UriEncodeCheckEscapes,
            RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 16";

    aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%EF%BF%BF"));
        // \U+FFFF is no legal character
    aText2 = aText1;
    ASSERT_TRUE((rtl::Uri::encode(
            aText1, rtl_UriCharClassUric, rtl_UriEncodeCheckEscapes,
            RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 17";

    // Check IURI handling:

    aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%30%C3%BF"));
    aBuffer.appendAscii(RTL_CONSTASCII_STRINGPARAM("%30"));
    aBuffer.append(static_cast< sal_Unicode >(0x00FF));
    aText2 = aBuffer.makeStringAndClear();
    ASSERT_TRUE((rtl::Uri::decode(aText1, rtl_UriDecodeToIuri, RTL_TEXTENCODING_UTF8)
         == aText2)) << 
        "failure 18";

    // Check modified rtl_UriCharClassUnoParamValue (removed '[' and ']'):

    aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("[]%5B%5D"));
    aText2 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%5B%5D%5B%5D"));
    ASSERT_TRUE((rtl::Uri::encode(
            aText1, rtl_UriCharClassUnoParamValue, rtl_UriEncodeCheckEscapes,
            RTL_TEXTENCODING_ASCII_US)
         == aText2)) << 
        "failure 19";

    // Check Uri::convertRelToAbs:

    struct RelToAbsTest
    {
        char const * pBase;
        char const * pRel;
        char const * pAbs;
    };
    static RelToAbsTest const aRelToAbsTest[]
        = { // The following tests are taken from RFC 2396:
            { "http://a/b/c/d;p?q", "g:h", "g:h" },
            { "http://a/b/c/d;p?q", "g", "http://a/b/c/g" },
            { "http://a/b/c/d;p?q", "./g", "http://a/b/c/g" },
            { "http://a/b/c/d;p?q", "g/", "http://a/b/c/g/" },
            { "http://a/b/c/d;p?q", "/g", "http://a/g" },
            { "http://a/b/c/d;p?q", "//g", "http://g" },
            { "http://a/b/c/d;p?q", "?y", "http://a/b/c/?y" },
            { "http://a/b/c/d;p?q", "g?y", "http://a/b/c/g?y" },
            { "http://a/b/c/d;p?q", "#s", "http://a/b/c/d;p?q#s" },
            { "http://a/b/c/d;p?q", "g#s", "http://a/b/c/g#s" },
            { "http://a/b/c/d;p?q", "g?y#s", "http://a/b/c/g?y#s" },
            { "http://a/b/c/d;p?q", ";x", "http://a/b/c/;x" },
            { "http://a/b/c/d;p?q", "g;x", "http://a/b/c/g;x" },
            { "http://a/b/c/d;p?q", "g;x?y#s", "http://a/b/c/g;x?y#s" },
            { "http://a/b/c/d;p?q", ".", "http://a/b/c/" },
            { "http://a/b/c/d;p?q", "./", "http://a/b/c/" },
            { "http://a/b/c/d;p?q", "..", "http://a/b/" },
            { "http://a/b/c/d;p?q", "../", "http://a/b/" },
            { "http://a/b/c/d;p?q", "../g", "http://a/b/g" },
            { "http://a/b/c/d;p?q", "../..", "http://a/" },
            { "http://a/b/c/d;p?q", "../../", "http://a/" },
            { "http://a/b/c/d;p?q", "../../g", "http://a/g" },
            { "http://a/b/c/d;p?q", "", "http://a/b/c/d;p?q" },
            { "http://a/b/c/d;p?q", "../../../g", "http://a/../g" },
            { "http://a/b/c/d;p?q", "../../../../g", "http://a/../../g" },
            { "http://a/b/c/d;p?q", "/./g", "http://a/./g" },
            { "http://a/b/c/d;p?q", "/../g", "http://a/../g" },
            { "http://a/b/c/d;p?q", "g.", "http://a/b/c/g." },
            { "http://a/b/c/d;p?q", ".g", "http://a/b/c/.g" },
            { "http://a/b/c/d;p?q", "g..", "http://a/b/c/g.." },
            { "http://a/b/c/d;p?q", "..g", "http://a/b/c/..g" },
            { "http://a/b/c/d;p?q", "./../g", "http://a/b/g" },
            { "http://a/b/c/d;p?q", "./g/.", "http://a/b/c/g/" },
            { "http://a/b/c/d;p?q", "g/./h", "http://a/b/c/g/h" },
            { "http://a/b/c/d;p?q", "g/../h", "http://a/b/c/h" },
            { "http://a/b/c/d;p?q", "g;x=1/./y", "http://a/b/c/g;x=1/y" },
            { "http://a/b/c/d;p?q", "g;x=1/../y", "http://a/b/c/y" },
            { "http://a/b/c/d;p?q", "g?y/./x", "http://a/b/c/g?y/./x" },
            { "http://a/b/c/d;p?q", "g?y/../x", "http://a/b/c/g?y/../x" },
            { "http://a/b/c/d;p?q", "g#s/./x", "http://a/b/c/g#s/./x" },
            { "http://a/b/c/d;p?q", "g#s/../x", "http://a/b/c/g#s/../x" },
            { "http://a/b/c/d;p?q", "http:g", "http:g" },
            { "http!://a/b/c/d;p?q", "g:h", "g:h" },
            { "http!://a/b/c/d;p?q", "g", 0 },
            { "http:b/c/d;p?q", "g:h", "g:h" },
            { "http:b/c/d;p?q", "g", 0 },
            { "http://a/b/../", "../c", "http://a/b/../../c" },
            { "http://a/b/..", "../c", "http://a/c" },
            { "http://a/./b/", ".././.././../c", "http://a/./../../c" } };
    for (std::size_t i = 0; i < sizeof aRelToAbsTest / sizeof (RelToAbsTest); ++i)
    {
        rtl::OUString aAbs;
        bool bMalformed = false;
        try {
            aAbs = rtl::Uri::convertRelToAbs(
                rtl::OUString::createFromAscii(aRelToAbsTest[i].pBase),
                rtl::OUString::createFromAscii(aRelToAbsTest[i].pRel));
        } catch (rtl::MalformedUriException &) {
            bMalformed = true;
        }
        if (bMalformed
            ? aRelToAbsTest[i].pAbs != 0
            : (aRelToAbsTest[i].pAbs == 0
               || !aAbs.equalsAscii(aRelToAbsTest[i].pAbs)))
        {
            printf(
                "FAILED convertRelToAbs(%s, %s) -> %s != %s\n",
                aRelToAbsTest[i].pBase, aRelToAbsTest[i].pRel,
                (bMalformed
                 ? "<MALFORMED>"
                 : rtl::OUStringToOString(
                     aAbs, RTL_TEXTENCODING_UTF8).getStr()),
                (aRelToAbsTest[i].pAbs == 0
                 ? "<MALFORMED>" : aRelToAbsTest[i].pAbs));
            FAIL();
        }
    }

    // Check encode with unusual text encodings:

    {
        sal_Unicode const aText1U[] = { ' ', '!', 0x0401, 0x045F, 0 };
        aText1 = rtl::OUString(aText1U);
        aText2 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%20!%A1%FF"));
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeIgnoreEscapes,
                RTL_TEXTENCODING_ISO_8859_5)
             == aText2)) << 
            "failure 20";
        ASSERT_TRUE((rtl::Uri::decode(
                aText2, rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ISO_8859_5)
             == aText1)) << 
            "failure 20a";
    }
    {
        sal_Unicode const aText1U[] = { ' ', '!', 0x0401, 0x0700, 0x045F, 0 };
        aText1 = rtl::OUString(aText1U);
        sal_Unicode const aText2U[] = {
            '%', '2', '0', '!', '%', 'A', '1', 0x0700, '%', 'F', 'F', 0 };
        aText2 = rtl::OUString(aText2U);
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeIgnoreEscapes,
                RTL_TEXTENCODING_ISO_8859_5)
             == aText2)) << 
            "failure 21";
        ASSERT_TRUE((rtl::Uri::decode(
                aText2, rtl_UriDecodeWithCharset, RTL_TEXTENCODING_ISO_8859_5)
             == aText1)) << 
            "failure 21a";
    }
    {
        sal_Unicode const aText1U[] = { ' ', '!', 0x028A, 0xD849, 0xDD13, 0 };
        aText1 = rtl::OUString(aText1U);
        aText2 = rtl::OUString(
            RTL_CONSTASCII_USTRINGPARAM("%20!%81%30%B1%33%95%39%C5%37"));
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeIgnoreEscapes,
                RTL_TEXTENCODING_GB_18030)
             == aText2)) << 
            "failure 22";
        ASSERT_TRUE((rtl::Uri::decode(
                aText2, rtl_UriDecodeWithCharset, RTL_TEXTENCODING_GB_18030)
             == aText1)) << 
            "failure 22a";
    }

    // Check strict mode:

    {
        sal_Unicode const aText1U[] = { ' ', '!', 0x0401, 0x0700, 0x045F, 0 };
        aText1 = rtl::OUString(aText1U);
        aText2 = rtl::OUString();
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeStrict,
                RTL_TEXTENCODING_ISO_8859_5)
             == aText2)) << 
            "failure 23";
    }
    {
        aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%20%C4%80%FF"));
        aText2 = rtl::OUString();
        ASSERT_TRUE((rtl::Uri::decode(
                aText1, rtl_UriDecodeStrict, RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 24";
    }
    {
        aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%81 "));
        aText2 = rtl::OUString();
        ASSERT_TRUE((rtl::Uri::decode(
                aText1, rtl_UriDecodeStrict, RTL_TEXTENCODING_GB_18030)
             == aText2)) << 
            "failure 25";
    }
    {
        aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%81%20"));
        aText2 = rtl::OUString();
        ASSERT_TRUE((rtl::Uri::decode(
                aText1, rtl_UriDecodeStrict, RTL_TEXTENCODING_GB_18030)
             == aText2)) << 
            "failure 26";
    }
    {
        aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%81%30%B1%33"));
        sal_Unicode const aText2U[] = { 0x028A, 0 };
        aText2 = rtl::OUString(aText2U);
        ASSERT_TRUE((rtl::Uri::decode(
                aText1, rtl_UriDecodeStrict, RTL_TEXTENCODING_GB_18030)
             == aText2)) << 
            "failure 27";
    }
    {
        aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%810%B13"));
        sal_Unicode const aText2U[] = { 0x028A, 0 };
        aText2 = rtl::OUString(aText2U);
        ASSERT_TRUE((rtl::Uri::decode(
                aText1, rtl_UriDecodeStrict, RTL_TEXTENCODING_GB_18030)
             == aText2)) << 
            "failure 28";
    }

    // Check rtl_UriEncodeStrictKeepEscapes mode:

    {
        aText1 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%%ea%c3%aa"));
        aText2 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%25%EA%C3%AA"));
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeStrictKeepEscapes,
                RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 29";
    }
    {
        sal_Unicode const aText1U[] = { 0x00EA, 0 };
        aText1 = rtl::OUString(aText1U);
        aText2 = rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("%C3%AA"));
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeStrictKeepEscapes,
                RTL_TEXTENCODING_UTF8)
             == aText2)) << 
            "failure 30";
    }
    {
        sal_Unicode const aText1U[] = { ' ', '!', 0x0401, 0x0700, 0x045F, 0 };
        aText1 = rtl::OUString(aText1U);
        aText2 = rtl::OUString();
        ASSERT_TRUE((rtl::Uri::encode(
                aText1, rtl_UriCharClassUric, rtl_UriEncodeStrictKeepEscapes,
                RTL_TEXTENCODING_ISO_8859_5)
             == aText2)) << 
            "failure 23";
    }
}

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

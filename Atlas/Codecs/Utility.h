// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Stefanus Du Toit, Michael Day

#ifndef ATLAS_CODECS_UTILITY_H
#define ATLAS_CODECS_UTILITY_H

/** @file Codecs/Utility.h
 * Various utility functions for codec implementation.
 *
 * This file contains various functions that can be used in implementing an
 * Atlas::Codec.
 *
 * @see Atlas::Codec
 * @author Stefanus Du Toit <sdt@gmx.net>, Michael Day <mikeday@corplink.com.au>
 */

#include <cstdio>
#include <string>
#include <algorithm>

namespace Atlas { namespace Codecs {
  
/// Convert an ASCII char to its hexadecimal value
inline const std::string charToHex(char c)
{
    char hex[3];
#ifdef WIN32
    _snprintf(hex, 3, "%x", c);
#else
    snprintf(hex, 3, "%x", c);
#endif
    return hex;
}

/// Convert a string with a hexadecimal value (2 characters) to an ASCII char
inline char hexToChar(const std::string& hex)
{
    int c;
    sscanf(hex.c_str(), "%x", &c);
    return c;
}

/** Escape a string by converting certain characters to their hexadecimal
 * value.
 *
 * @return The escaped message.
 * @param prefix The string that is to be prepended to the hexadecimal value.
 * @param special The characters that are to be escaped.
 * @param message The message that is to be escaped.
 * @see hexDecode
 */
inline const std::string hexEncode(const std::string& prefix,
        const std::string& special, const std::string& message)
{
    std::string encoded;

    for (std::string::const_iterator i = message.begin();
         i != message.end(); ++i)
    {
	if (std::find(special.begin(), special.end(), *i) != special.end())
	{
	    encoded += prefix;
	    encoded += charToHex(*i);
	}
	else
	{
	    encoded += *i;
	}
    }

    return encoded;
}

/** Parse a message and replace hexadecimal 'escaped' values with their ASCII
 * counterparts.
 *
 * This function does the opposite to hexDecode - it takes a message that was
 * prepared with hexDecode, searches for occurences of prefix and replaces the
 * following hexadecimal values with their ASCII counterparts.
 *
 * @return The unescaped string.
 * @param prefix The string that is followed by the escaped characters
 * @param message The escaped message.
 */
inline const std::string hexDecode(const std::string& prefix,
                                   const std::string& message)
{
    std::string newMessage;
    std::string curFragment;
    
    for (size_t i = 0; i < message.size(); i++) {
        if (std::equal(prefix.begin(),prefix.begin() + curFragment.length() + 1,
                    (curFragment + message[i]).begin())) {
            curFragment += message[i];
        } else {
            newMessage += curFragment + message[i];
            curFragment = "";
        }
        if (curFragment == prefix) {
            std::string hex;
            hex += message[++i];
            hex += message[++i];
            newMessage += hexToChar(hex);
            curFragment = "";
        }
    }

    return newMessage;
}

} } // namespace Atlas::Codecs

#endif

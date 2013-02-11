/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Exception.hpp"

Err::Exception::Exception(int number = 0, std::string const& text = "", int level = 0) throw() :m_number(number),m_text(text),m_level(level) {}

const char* Err::Exception::what() const throw()
{
    return m_text.c_str();
}

int Err::Exception::getLevel() const throw()
{
    return m_level;
}

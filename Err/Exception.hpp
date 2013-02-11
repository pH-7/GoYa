/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef EXCEPTION_ERR_H_INCLUDED
#define EXCEPTION_ERR_H_INCLUDED

#include <string>
#include <exception>

namespace Err
{

    class Exception: public std::exception
    {
        public:
        Exception(int, std::string const&, int) throw();

        virtual const char* what() const throw();

        int getLevel() const throw();

        virtual ~Exception() throw() {}

        private:
        int m_number; // Error number
        std::string m_text; // Error description
        int m_level; // Error level
    };

}

#endif // EXCEPTION_ERR_H_INCLUDED

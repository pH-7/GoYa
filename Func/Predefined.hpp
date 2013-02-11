/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef PREDEFINED_FUNC_H_INCLUDED
#define PREDEFINED_FUNC_H_INCLUDED

#include <string>

namespace Func
{
    class Predefined
    {
        public:
        std::string fileRead(std::string fileName);
        bool fileWrite(std::string fileName, std::string const& content);
    };
}

#endif // PREDEFINED_FUNC_H_INCLUDED

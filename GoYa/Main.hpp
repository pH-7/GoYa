/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef MAIN_GOYA_H_INCLUDED
#define MAIN_GOYA_H_INCLUDED

#include <iostream>

namespace GoYa
{
    class Main
    {
        public:
        static const char* VERSION;
        static const std::string NAME;
        static std::string welcome();
        static std::string softwareVersion();
        static std::string showHelp();
        static std::string showLicense();
        static std::string showCredits();
    };
}

#endif // MAIN_GOYA_H_INCLUDED

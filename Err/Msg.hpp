/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef MSG_ERR_H_INCLUDED
#define MSG_ERR_H_INCLUDED

#include <iostream>

namespace Err
{
    class Msg
    {
        public:
        // Launch (Exception)
        static void launchErr(std::string);
        static void launchWarn(std::string);

        // Show (Output)
        static void showErr(std::string);
        static void showWarn(std::string);
    };
}

#endif // MSG_ERR_H_INCLUDED

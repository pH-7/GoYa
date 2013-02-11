/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Msg.hpp"

using namespace std;

void Err::Msg::launchErr(string msg)
{
    throw string("ERROR: " + msg);
}

void Err::Msg::launchWarn(string msg)
{
    throw string("WARNING:" + msg);
}

void Err::Msg::showErr(string msg)
{
    cout << "ERROR: " << msg << endl;
}

void Err::Msg::showWarn(string msg)
{
    cout << "WARNING:" << msg << endl;
}

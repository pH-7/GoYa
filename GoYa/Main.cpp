/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Main.hpp"

using namespace std;

const char* GoYa::Main::VERSION = "0.0.6";
const string GoYa::Main::NAME = "GoYa";

string GoYa::Main::welcome()
{
    string text;
    text = "Welcome to interpreter \"" + NAME + " Language\"\r\n";
    text += "Copyright (c) 2012, Pierre-Henry Soria. All Rights Reserved.\r\n";
    text += "Type \"-help\", \"-version\", \"-license\" or \"-credits\" for more information.\r\n\r\n";

    return text;
}

string GoYa::Main::softwareVersion()
{
    return NAME + " " + VERSION + "\r\n";
}

string GoYa::Main::showHelp()
{
    string text;
    text = "----- " + NAME + " HELP -----\r\n";
    text += "Usage: <PROGRAMM EXE> <file>\r\n";
    text += "-V, -version     : The number version\r\n";
    text += "-H, -help        : Help about " + NAME + "\r\n";

    return text;
}

string GoYa::Main::showLicense()
{
    return "See here: http://github.com/pH-7/GoYa/blob/master/LICENSE.txt\r\n";
}

string GoYa::Main::showCredits()
{
    string text;
    text = "----- Credits -----\r\n";
    text += "Author: Pierre-Henry Soria\r\n";
}

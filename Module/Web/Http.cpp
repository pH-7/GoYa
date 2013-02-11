/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Http.hpp"

using namespace std;

/**
 * For the HTML pages.
 */
void Web::Http::defaultHtmlHeaders()
{
    string softwareVersion = GoYa::Main::softwareVersion();

    cout << "HTTP/1.1 200 OK\r\n";
    cout << "Status: 200 OK\r\n";
    cout << "Server: " << softwareVersion << "\r\n";
    cout << "X-Powered-By: " << softwareVersion << "\r\n";
    cout << "X-Content-Encoded-By: " << softwareVersion << "\r\n";
    cout << "Accept-Ranges: bytes\r\n";
    cout << "Content-Length: 64\r\n";
    cout << "Connection: close\r\n";
    // Mandatory, otherwise how can he know that this is an HTML document
    // and your server will respond error 500.
    cout << "Content-Type: text/html; charset=utf-8\r\n";
    cout << "\r\n";
    /*
    string s0;
    char *pc= getenv("CONTENT_TYPE");
    if (  pc == NULL )
    {
        cout << "Content-Type: text/plain\n\n";
    }
    s0 = string( pc );
    if (  s0 != std::string("application/x-www-form-urlencoded") )
    {
        cout << "Content-Type: text/plain\n\n";
    }
    */
}

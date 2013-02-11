/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2012-2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include <cstdlib> // C library
#include <cstring> // C library

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "GoYa/Main.hpp"
#include "Parser/Token.hpp"
#include "Interpreter/Base.hpp"
#include "Err/Msg.hpp"
#include "Err/Exception.hpp"

using namespace std;

int main(int argc, char** const argv)
{
    try
    {
        Func::Core::system();
        Parser::Token sequence;
        string input;

        if( argc > 1 )
        {

            if (!strcmp(argv[1], "-V") || !strcmp(argv[1], "-version"))
            {
                cout << GoYa::Main::softwareVersion();
                return EXIT_SUCCESS;
            }
            else if (!strcmp(argv[1], "-H") || !strcmp(argv[1], "-help"))
            {
                cout << GoYa::Main::showHelp();
                return EXIT_SUCCESS;
            }
            else if (!strcmp(argv[1], "-license"))
            {
                cout << GoYa::Main::showLicense();
                return EXIT_SUCCESS;
            }
            else if (!strcmp(argv[1], "-credits"))
            {
                cout << GoYa::Main::showCredits();
                return EXIT_SUCCESS;
            }
            else
            {
                ifstream iFile( argv[1] );
                if( iFile.is_open() )
                {
                    while( !iFile.eof() )
                    {
                        getline(iFile, input);
                        Parser::Token sequence( sequence.get(input) );;
                        Interpreter::Base::interpret(sequence);
                    }
                }
                else
                {
                    Err::Msg::showErr("Couldn't open file '" + (string)argv[1] + "'");
                }
                iFile.close();
            }
        }
        else
        {
            cout << GoYa::Main::welcome();
            while(1)
            {
                cout << ">>> ";
                getline(cin, input);
                Parser::Token sequence( sequence.get(input) );
                Interpreter::Base::interpret(sequence);
                cout << endl;
            }
        }
        return 0;
    }
    catch (Err::Exception const& e)
    {
        cerr << GoYa::Main::NAME << "Exception: " << e.what() << endl;
    }
    catch (string const& text)
    {
        cerr << text << endl;
    }
    catch (int const& digit)
    {
        cerr << "Integer Exception: " << digit << endl;
    }
    catch (double const& digit)
    {
        cerr << "Double Exception: " << digit << endl;
    }
    catch (runtime_error const& e)
    {
        cerr << "Exception during runtime: " << e.what() << endl;
    }
    catch (exception const& e)
    {
        cerr << e.what() << endl;
    }
}

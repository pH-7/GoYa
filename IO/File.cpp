/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "File.hpp"

using namespace std;

IO::File::File(string const& fileName)
{
    m_fstream = new fstream(fileName.c_str());
}

IO::File::~File()
{
    m_fstream->close();
    delete m_fstream;
}

string IO::File::read()
{
    string bf = "";

    if (m_fstream->is_open())
    {
        char c;
        m_fstream->get(c);
        bf += c;
        while ( !m_fstream->eof() )
        {
            m_fstream->get(c);
            bf += c;
        }
    }
    else
    {
        throw string("File could not be found.");
    }

    if(bf.empty()) throw string("The file cannot be empty!");

    return bf;
}

bool IO::File::put(string const& content)
{
    bool status;

    if(m_fstream->is_open())
    {
        *m_fstream << content << endl;
        status = true;
    }
    else
    {
        throw string("File could not be open.");
        status = false;
    }

    return status;
}

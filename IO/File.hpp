/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef FILE_IO_H_INCLUDED
#define FILE_IO_H_INCLUDED

#include <fstream>
#include <string>

namespace IO
{
    class File
    {
        public:
        File(std::string const&);
        ~File();
        std::string read();
        bool put(std::string const&);

        private:
        std::fstream *m_fstream;
    };

}

#endif // FILE_IO_H_INCLUDED

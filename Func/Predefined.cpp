/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Predefined.hpp"
#include "../IO/File.hpp"

std::string Func::Predefined::fileRead(std::string fileName)
{
    IO::File file(fileName);
    return file.read();
}

bool Func::Predefined::fileWrite(std::string fileName, std::string const& content)
{
    IO::File file(fileName);
    return file.put(content);
}

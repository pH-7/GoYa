/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef LEX_LEXER_H_INCLUDED
#define LEX_LEXER_H_INCLUDED

#include <string>

namespace Lexer
{
    class Lex
    {
        public:
        Lex();
        ~Lex();

        static std::string LEFT_TAG;
        static std::string RIGHT_TAG;
    };

}

#endif // LEX_LEXER_H_INCLUDED

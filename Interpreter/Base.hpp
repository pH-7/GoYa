/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef BASE_INTERPRETER_H_INCLUDED
#define BASE_INTERPRETER_H_INCLUDED

#include "../Parser/Token.hpp"
#include "../Module/init.hpp"
#include "../Obj/Core.hpp"
#include "../Func/Core.hpp"
#include "../Operator/Core.hpp"
#include "../Lexer/Lex.hpp"

namespace Interpreter
{
    class Base
    {
        public:
        static void interpret(Parser::Token&);
    };
}

#endif // BASE_INTERPRETER_H_INCLUDED

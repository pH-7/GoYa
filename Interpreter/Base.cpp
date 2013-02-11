/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Base.hpp"

using namespace Lexer;

void Interpreter::Base::interpret( Parser::Token& seq )
{
    Operator::Core *operatorCore;
    operatorCore = new Operator::Core;

    Obj::Core *obj;
    obj = new Obj::Core;

    Func::Core *func;
    func = new Func::Core;

    bool ok = true; // Default value

    while( ok && !seq.empty() ) {
        while ( (seq.cur() == "#" && !seq.isNext("\n")) ) seq.next(); // Ignore the comments
        if ( seq.cur() == "class" )
            ok = obj->defineClass(seq);
        else if( seq.cur() == "func" )
            ok = func->defineFunction(seq);
        else if( seq.cur()== "=" && !seq.isNext( Lex::LEFT_TAG ) )
            ok = operatorCore->opAssignment(seq);
        else if( seq.cur() == "then" )
            ok = operatorCore->opThen(seq);
        else if( seq.cur() == "else" )
            ok = operatorCore->opElse(seq);
        else if( seq.cur() == "?" )   // "?" is ignored since it is a placeholder
            seq.next();
        else
            ok = func->interpStatement(seq);
    }

    delete operatorCore;
    delete obj;
    delete func;
}

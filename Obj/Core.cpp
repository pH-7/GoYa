/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Core.hpp"
#include "../Lexer/Lex.hpp"

using namespace std;
using namespace Lexer;
using namespace Err;

// Initialize static members
set<Obj::Core> Obj::Core::m_definedClasses;

Obj::Core::Core() {};

Obj::Core::Core(string n, string c, const Parser::Token& b = Parser::Token()) : m_name(n), m_content(c), m_body(b) {}

bool Obj::Core::defineClass( Parser::Token& seq )
{
    // Extract class name
    if( !seq.next() ) goto badFunc;
    m_name = seq.cur();

    // Create an object class
    if( !seq.next() ) goto badFunc;
    m_content = seq.cur();

    while( seq.next() && !seq.isNext("class") )
        m_body.append( seq.cur() );

    m_definedClasses.insert(*this);
    return true;

badFunc:
    Msg::showErr("Invalid object class definition.");
    if( !m_name.empty() ) cout << " '" << m_name << "'" << endl;
    return false;
}

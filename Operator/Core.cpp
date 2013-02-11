/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include <iostream>
#include "Core.hpp"

using namespace std;

/**
 * Variable assignment.
 */
bool Operator::Core::opAssignment( Parser::Token& seq )
{
    if( !seq.next() ) {
        cout << "ERROR: Assignment incomplete." << endl;
        return false;
    }
    if( !isVariable(seq.cur()) ) {
        cout << "ERROR: Assignment to non-variable." << endl;
        return false;
    }
    setVariable(seq.cur(), m_numBuffer);
    seq.next();
    return true;
}

/**
 * Ternary operator.
 */
bool Operator::Core::opElse( Parser::Token& seq )
{
    bool found = false;
    while( seq.next() && !found )
        found = (seq.cur() == "?");
    return found;
}

/**
 * Test the m_numBuffer variable.
   If it is true, just return (execution will continue in interpret's loop).
 * otherwise go to the following tokens until we hit either "else" or "?", (also go to the following tokens if both are found).
 */
bool Operator::Core::opThen( Parser::Token& seq )
{
    if( m_numBuffer == 0 )
    {
        bool done=false;
        while( !done && seq.next() )
            done = (seq.cur() == "?") || (seq.cur() == "else");

        if( !done )
        {
            cout << "ERROR: Conditional incomplete." << endl;
            return false;
        }
    }

    seq.next(); // Go to next if "then" condition is true, "else" or "?" otherwise
    return true;
}

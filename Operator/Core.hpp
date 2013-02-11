/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef CORE_OPERATOR_H_INCLUDED
#define CORE_OPERATOR_H_INCLUDED

#include "../Func/Core.hpp"
#include "../Parser/Token.hpp"

namespace Operator
{

    class Core : public Func::Core
    {
        public:
        bool opAssignment( Parser::Token& );
        bool opElse( Parser::Token& );
        bool opThen( Parser::Token& );
    };

}

#endif // CORE_OPERATOR_H_INCLUDED

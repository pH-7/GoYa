                                                                                                                       /*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef CORE_OBJ_H_INCLUDED
#define CORE_OBJ_H_INCLUDED

#include <iostream>
#include <set>
#include "../Parser/Token.hpp"
#include "../Func/Core.hpp"
#include "../Err/Msg.hpp"

namespace Obj
{

    class Core : public Parser::Token, public Func::Core
    {
        public:
        Core();
        Core(std::string, std::string, const Parser::Token&);
        bool defineClass( Parser::Token& );
        typedef std::set<Core> funcSet;

        private:
        std::string m_name;
        static funcSet m_definedClasses;
        std::string m_content;
        Parser::Token m_body;
    };

}

#endif // CORE_OBJ_H_INCLUDED




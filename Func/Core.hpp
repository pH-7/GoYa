/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef CORE_FUNC_H_INCLUDED
#define CORE_FUNC_H_INCLUDED

#include <cstdio> // C library
#include <cstdlib> // C library

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include "../Parser/Token.hpp"
#include "Stack.hpp"
#include "../Err/Msg.hpp"

namespace Func
{

    class Core : public Parser::Token
    {
        public:
        Core();
        Core(std::string, unsigned int, const Parser::Token&);
        Core(const Core&);

        Core& operator=(const Core&);
        bool operator<(const Core&) const;

        static void system();
        std::string allBufferToStr();
        bool interpStatement( Parser::Token&);
        bool callFunction( std::string, std::vector<double> );
        bool defineFunction( Parser::Token& );
        bool isWhiteSpace( std::string );
        bool isChar( std::string );
        bool isString( std::string );
        int isAlpha( std::string );
        bool isVariable( std::string );
        double variableValue( std::string );
        void setVariable( std::string, double );
        bool isNumber( std::string );
        std::string print();
        int systemCode();
        void cleanVars();

        typedef std::set<Core> funcSet;

        protected:
        static double m_numBuffer;
        static char m_charBuffer;
        static std::string m_strBuffer;

        private:
        static std::vector<Stack> m_scope;
        static funcSet m_definedFunctions;
        unsigned int m_args;
        std::string m_name;
        Parser::Token m_body;
    };

}

#endif // CORE_FUNC_H_INCLUDED




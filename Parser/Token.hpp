/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef TOKEN_PARSER_H_INCLUDED
#define TOKEN_PARSER_H_INCLUDED

#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <list>

namespace Parser
{
    typedef std::list<std::string> tokenList;

    class Token
    {
        public:
        Token();
        Token( const tokenList& );
        void parse();
        tokenList get(std::string);
        void append( const tokenList& );
        void append( std::string tok );
        void clear();
        bool empty() const;
        std::string cur() const;
        bool next();
        bool find(const std::string&);
        bool isFront( std::string ) const;
        bool isNext( std::string ) const;

        protected:
        bool checkSize() const;
        static std::set<char> m_specialTokens;

        private:
        tokenList m_tokens;
    };
}

#endif // TOKEN_PARSER_H_INCLUDED

/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#include "Token.hpp"

using namespace std;

// Initialize static member
set<char> Parser::Token::m_specialTokens;

Parser::Token::Token() {}

Parser::Token::Token( const tokenList& l )
{
    append(l);
}

void Parser::Token::parse()
{

}

Parser::tokenList Parser::Token::get(string src)
{
    Parser::tokenList toks;
    string work;

    for( unsigned int i=0; i<src.length(); i++ )
    {
        if( src[i] == ',' ) {
            if( !work.empty() ) {
                toks.push_back(work);
                work = "";
            }
        } else if( m_specialTokens.count(src[i]) ) {
            if( !work.empty() ) {
                toks.push_back(work);
                work = "";
            }
            work.append(1, src[i]);
            toks.push_back(work);
            work = "";
        } else {
            work.append(1, src[i]);
        }
    }

    if( !work.empty() )
        toks.push_back(work);

    return toks;
}

void Parser::Token::append(const Parser::tokenList& l)
{
    m_tokens.insert(m_tokens.end(), l.begin(), l.end());
}

void Parser::Token::append(string tok)
{
     m_tokens.push_back(tok);
}

void Parser::Token::clear()
{
    m_tokens.clear();
}

bool Parser::Token::empty() const
{
    return m_tokens.empty();
}

string Parser::Token::cur() const
{
    return m_tokens.front();
}

bool Parser::Token::next()
{
    if (!empty()) m_tokens.pop_front();
    return !empty();
}

bool Parser::Token::find(const string& str)
{
    list<string>::iterator findIter = ::find(m_tokens.begin(), m_tokens.end(), str);
    return (*findIter == str);
}

bool Parser::Token::isFront(string t) const
{
    return (!checkSize()) ? false : t == *(--m_tokens.end());
}

bool Parser::Token::isNext(string t) const
{
    return (!checkSize()) ? false : t == *(++m_tokens.begin());
}

bool Parser::Token::checkSize() const
{
    return (m_tokens.size() <= 1) ? false : true;
}


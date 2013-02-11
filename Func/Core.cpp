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
#include "../Interpreter/Base.hpp"
#include "../Lexer/Lex.hpp"

using namespace std;
using namespace Lexer;
using namespace Err;

// Initialize static members
vector<Func::Stack> Func::Core::m_scope;
set<Func::Core> Func::Core::m_definedFunctions;
//double Func::Core::m_currentValue(0.0);
double Func::Core::m_numBuffer = NULL;
char Func::Core::m_charBuffer = NULL;
std::string Func::Core::m_strBuffer = "";

Func::Core::Core() : m_args(0) {}
Func::Core::Core(string n, unsigned int a, const Parser::Token& b=Parser::Token()) : m_args(a), m_name(n), m_body(b) {}
Func::Core::Core(const Func::Core& f) { *this = f; }

Func::Core& Func::Core::operator=(const Func::Core& f)
{
    m_args = f.m_args;
    m_name = f.m_name;
    m_body = f.m_body;
    return *this;
}

bool Func::Core::operator<(const Func::Core& f) const
{
    if( m_name < f.m_name ) return true;
        return (m_name == f.m_name) && (m_args<f.m_args);
}

template <typename T, typename S>
T static stream_cast( S const& val )
{
    stringstream stream(val);
    T rc;
    stream >> rc;
    return rc;
}

template <typename T>
string convertToStr( T const& val )
{
    ostringstream convert;
    convert << val;
    return convert.str();
}

string Func::Core::allBufferToStr()
{
    string str;

    if( !m_strBuffer.empty() )
        str = m_strBuffer;
    else if( m_charBuffer != NULL )
        str = convertToStr<char>(m_charBuffer);
    else if( m_numBuffer != NULL )
        str = convertToStr<double>(m_numBuffer);
    else
        Msg::launchErr("Empty Output Stream.");

    return str;
}

bool Func::Core::isWhiteSpace( string str )
{
    return (str  == " ") || (str  == "\t") || (str  == "\r")
        || (str  == "\n") || (str  == "\v");
}

bool Func::Core::isString( string str )
{
    return (str.empty() == (str == std::string()));
}

bool Func::Core::isChar( string str )
{
    return (isString(str) && str.size() == 1);
}

/*
 * Returns the number of alphabet letter found. Returns 0 if no letter of the alphabet is found.
 */
int Func::Core::isAlpha( string str )
{
    string letters = "qwertyuiopasdfghjklzxcvbnm";
    int static foundCount = 0;

    for (string::iterator it = str.begin(); it != str.end(); ++it)
        if(letters.find(*it)) foundCount++;

    return foundCount;
}

bool Func::Core::isNumber( string str )
{
    unsigned int i = 0;
    if( !str.empty() && (str[i] == '-' || str[i] == '+') ) i++;
    return string::npos == str.find_first_not_of( ".eE0123456789", i );
}

bool Func::Core::isVariable( string tag )
{
    return (tag == "x") || (tag == "y") || (tag == "z")
        || (tag == "i") || (tag == "j") || (tag == "k");
}

string Func::Core::print()
{
    string output = allBufferToStr();
    cleanVars();
    return output;
}

int Func::Core::systemCode()
{
    int ret = ::system(m_strBuffer.c_str());
    cleanVars();
    return ret;
}

double Func::Core::variableValue( string tag )
{
    if( tag == "x" ) return m_scope.front().v1;
    if( tag == "y" ) return m_scope.front().v2;
    if( tag == "y" ) return m_scope.front().v3;

    if( tag == "i" ) return m_scope.back().v1;
    if( tag == "j" ) return m_scope.back().v2;
    if( tag == "k" ) return m_scope.back().v3;

    Msg::showWarn("Invalid variable reference.");
    return 0;
}

void Func::Core::setVariable( string tag, double val )
{
    if( tag == "x" ) { m_scope.front().v1 = val; return; }
    if( tag == "y" ) { m_scope.front().v2 = val; return; }
    if( tag == "z" ) { m_scope.front().v3 = val; return; }

    if( tag == "i" ) { m_scope.back().v1 = val; return; }
    if( tag == "j" ) { m_scope.back().v2 = val; return; }
    if( tag == "k" ) { m_scope.back().v3 = val; return; }

    Msg::showWarn("Invalid variable assignment.");
}

bool Func::Core::callFunction( string func, vector<double> args )
{
    string bf;

    funcSet::iterator f = m_definedFunctions.find(Func::Core(func,args.size()));
    if( f == m_definedFunctions.end() ) {
        Msg::showErr("No function '" + func + "' with support for " + convertToStr<double>(args.size()) + " argument(s).");
        return false;
    }

    // If nobody code, then let's assume it is a system function
    if( f->m_body.empty() )
    {
        if( f->m_name == "+" )                 m_numBuffer = args[0] + args[1];
        else if( f->m_name == "-" )            m_numBuffer = args[0] - args[1];
        else if( f->m_name == "*" )            m_numBuffer = args[0] * args[1];
        else if( f->m_name == "/" )            m_numBuffer = args[0] / args[1];
        else if( f->m_name == "<" )            m_numBuffer = args[0] < args[1];
        else if( f->m_name == ">" )            m_numBuffer = args[0] > args[1];
        else if( f->m_name == "=" )            m_numBuffer = args[0] == args[1];
        else if( f->m_name == "<=" )           m_numBuffer = args[0] <= args[1];
        else if( f->m_name == ">=" )           m_numBuffer = args[0] >= args[1];
        else if( f->m_name == "nl")            cout << endl; // Nerw Line
        else if( f->m_name == "ends")          cout << ends; // Insert null character (end space \0)
        else if( f->m_name == "ws")            cout << " "; // White Space
        else if( f->m_name == "print")         cout << print();
        else if( f->m_name == "println")       cout << print() << endl;
        else if( f->m_name == "length")        m_numBuffer = print().length();
        else if( f->m_name == "input") {       getline(cin, bf); m_strBuffer = bf; }
        else if( f->m_name == "system")        systemCode();
        else if( f->m_name == "import::module")
        {
            if( m_strBuffer == "web" )
            {
                Web::Http *http;
                http = new Web::Http;

                // HTML Output
                http->defaultHtmlHeaders();

                delete http;
            }
            else
            {
                Msg::showErr("Module'" + m_strBuffer + "' nof found!");
            }
        }
    }
    else
    {
        // Setup scopes
        m_scope.push_back( Func::Stack() );
        switch(args.size())
        {
            default:
            case 3:     m_scope.back().v3 = args[2];
            case 2:     m_scope.back().v2 = args[1];
            case 1:     m_scope.back().v1 = args[0];
            case 0:     break;  // nothing
        }

        // Run body function, first make a copy because tokens are consumed
        Parser::Token run = f->m_body;
        Interpreter::Base::interpret(run);

        // Trash m_scope
        m_scope.pop_back();
    }

    return true;
}

bool Func::Core::interpStatement( Parser::Token& seq )
{
    bool ok = true;

    if( isVariable(seq.cur()) )
        m_numBuffer = variableValue(seq.cur());
    else if( seq.isNext( Lex::LEFT_TAG ) ) {
        vector<double> arguments;
        string func = seq.cur();
        seq.next(); // Skip past the function name
        seq.next(); // Causes a skip of Lexer::Lex::LEFT_TAG

        while( (ok =! seq.empty()) )
        {
            if( seq.cur() == Lex::RIGHT_TAG ) break; // Note, the 'Lexer::Lex::RIGHT_TAG' is removed at the end of this function!
            ok = interpStatement(seq);
            arguments.push_back(m_numBuffer);
        }

        if( ok ) {
            ok = callFunction(func, arguments);
        } else {
            Msg::showErr("Incomplete statement.");
            ok = false;
        }
    }
    else if( isNumber(seq.cur()) )
        m_numBuffer = stream_cast<double>(seq.cur());
    else if ( isChar(seq.cur()) )
        m_charBuffer = stream_cast<char>(seq.cur());
   else if ( isString(seq.cur()) && seq.isNext( Lex::RIGHT_TAG ))
       m_strBuffer = seq.cur();
    else {
        Msg::showErr("Unknown token '" + seq.cur() + "'");
        ok = false;
    }

    seq.next();
    return ok;
}

bool Func::Core::defineFunction( Parser::Token& seq )
{
    // Extract the function name
    if( !seq.next() ) goto badFunc;
    m_name = seq.cur();

    // Extract the function arguments
    if( !seq.next() ) goto badFunc;
    m_args = stream_cast<unsigned int>(seq.cur());
    if( m_args > 3 ) goto badFunc;

    // Search the end of the function
    while( seq.next() && !seq.isNext("func") ) // Create a user function
        m_body.append( seq.cur() );

    // Functions are added to the C++ set container
    m_definedFunctions.insert(*this);
    return true;

badFunc:
    Msg::showErr("Invalid function definition.");
    if( !m_name.empty() ) cout << " '" << m_name << "'" << endl;
    return false;
}

void Func::Core::cleanVars()
{
    m_numBuffer = NULL;
    m_charBuffer = NULL;
    m_strBuffer = "";
}

/**
 * Default system functions.
 */
void Func::Core::system()
{
    m_numBuffer = 0; // Default value
    m_scope.resize(1);

    // Adding functions with the C++ set container
    m_definedFunctions.insert( Func::Core(">",2) );
    m_definedFunctions.insert( Func::Core("<",2) );
    m_definedFunctions.insert( Func::Core("=",2) );
    m_definedFunctions.insert( Func::Core(">=",2) );
    m_definedFunctions.insert( Func::Core("<=",2) );
    m_definedFunctions.insert( Func::Core("+",2) );
    m_definedFunctions.insert( Func::Core("-",2) );
    m_definedFunctions.insert( Func::Core("*",2) );
    m_definedFunctions.insert( Func::Core("/",2) );
    m_definedFunctions.insert( Func::Core("nl",0) ); // New Line
    m_definedFunctions.insert( Func::Core("ends",0) ); // End space \0
    m_definedFunctions.insert( Func::Core("ws",0) ); // White Space
    m_definedFunctions.insert( Func::Core("print",1) );
    m_definedFunctions.insert( Func::Core("println",1) ); // Print Line New
    m_definedFunctions.insert( Func::Core("length",1) );
    m_definedFunctions.insert( Func::Core("input",0) );
    m_definedFunctions.insert( Func::Core("system",1) );

    // Import Module
    m_definedFunctions.insert( Func::Core("import::module",1) );

    m_specialTokens.insert( '=' );
    m_specialTokens.insert( stream_cast<char>(Lex::LEFT_TAG) );
    m_specialTokens.insert( stream_cast<char>(Lex::RIGHT_TAG) );
    m_specialTokens.insert( '?' );
}


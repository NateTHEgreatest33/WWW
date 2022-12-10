#include "utl.hpp"

#include <exception>


namespace gameplay 
{

void warning( bool compare, std::string s )
    {
    if( compare )
        {
        std::cout << "WARNING: "<< s << std::endl;
        }
    }

void abort( bool compare, std::string s )
    {
    if( compare )
        {
        std::cout << "ABORT: "<< s << std::endl;
        std::exit( 0 );
        }
    }





}
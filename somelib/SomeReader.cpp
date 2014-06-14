#include "SomeReader.h"
#include <iostream>
#include <sstream>

bool
SomeReader::read_from_stream(std::istream& input)
{
    std::stringstream strs;
    while( input ) {
        std::string tmp;
        input >> tmp;
        strs << tmp << ' ';
    }
    std::cout << ">>C++: " << strs.str( ) << std::endl;
    return true;
}

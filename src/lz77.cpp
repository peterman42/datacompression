#include "lz77.h"
#include <iostream>
#include <tuple>

LZ77::LZ77(std::string _payload)
	: payload(_payload)
{}


///////////////////////////////////////////////////////////////////////////////
void
LZ77::compress()
{
    std::tuple<int,int,std::string> tuple = {0, 0, ""};
    for(char character : payload)
    {
        std::cout << "Character :: " << character << std::endl;
    }
}

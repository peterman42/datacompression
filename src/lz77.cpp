#include "lz77.h"
#include <iostream>
#include <tuple>
#include <algorithm>

LZ77::LZ77( uint32_t _search_buffer_size
          , uint32_t _lookahead_buffer_size
          , std::string _payload)
    : search_buffer_size(_search_buffer_size)
    , lookahead_buffer_size(_lookahead_buffer_size)
    , payload(_payload)
    , tuples()
    , search_buffer()
    , lookahead_buffer()

{}


///////////////////////////////////////////////////////////////////////////////
void
LZ77::compress()
{
    // {0,0,""} 1: position, 2: length, 3: next character
    std::list buffer(payload.begin(), payload.end());
    for(char character : payload)
    {
        std::find_if(search_buffer.begin(),search_buffer.end(),[](auto tuple)
        {

        });

        std::cout << "Character :: " << character << std::endl;
    }
}

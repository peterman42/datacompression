#include "lz77.h"
#include <iostream>
#include <tuple>
#include <algorithm>

LZ77::LZ77( uint32_t _search_buffer_size
          , uint32_t _lookahead_buffer_size
          , const std::string& _payload)
    : search_buffer_size(_search_buffer_size)
    , lookahead_buffer_size(_lookahead_buffer_size)
    , payload(_payload)
    , tuples()
    , search_buffer()
    , lookahead_buffer()

{
    search_buffer.resize(_search_buffer_size);
    lookahead_buffer.resize(lookahead_buffer_size);

    // Initialize the lookahead buffer.
    lookahead_buffer.insert( lookahead_buffer.begin()
                           , payload.begin()
                           , payload.begin()+lookahead_buffer_size);
}


///////////////////////////////////////////////////////////////////////////////
void
LZ77::encode()
{
    // {0,0,""} 1: position, 2: length, 3: next character
    bool done = true;
    size_t cursor = 0;

    while(done)
    {
        //char next_char = -1;
        if(search_buffer.size() == 0)
        {
            char first_char = lookahead_buffer[0];
            tuples.push_back(std::make_tuple(-1,0,payload[0]));
            // Push the character into the search buffer.
            search_buffer.push_back(first_char);
        }
        else
        {
            char character = 1;
            while(true)
            {
                character = lookahead_buffer[cursor];
                auto itr = std::find(search_buffer.begin(), search_buffer.end(), character);
                if(itr != search_buffer.end())
                {

                    cursor = std::distance(search_buffer.begin(), itr);
                }

                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
std::string
LZ77::decode()
{
    return "";
}

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
            char first_char = lookahead_buffer.front();
            tuples.push_back(std::make_tuple(-1,0,first_char));

            // Push the character into the search buffer.
            search_buffer.push_back(first_char);

            // Pop one character from the lookahead_buffer
            lookahead_buffer.erase(lookahead_buffer.begin());

            // Pop one character from the lookahead_buffer
            lookahead_buffer.push_back(payload[cursor+lookahead_buffer_size]);

            // Increase cursor one position.
            cursor++;
        }
        else
        {
            int32_t position         = 0;                       // Position of first character that we found. This is the position that will be placed in the tuple.
            uint32_t length          = 0;                       // The length of matching pattern.
            bool found               = false;                   // This is a flag, marking that we found at least one character into the search_buffer.
            uint32_t current_lookahead_index = 0;               // The current index of character of lookahead_buffer that we looking for into the search_buffer.
            auto start_search_itr    = search_buffer.begin();   // The start iterator.
            auto end_search_itr      = search_buffer.end();     // The end iterator.
            while(true)
            {
                char character = lookahead_buffer[current_lookahead_index];
                auto itr = std::find(start_search_itr, end_search_itr, character);
                if(itr != end_search_itr)
                {
                    if(!found)
                    {
                        // Distance from the begining.
                        int32_t dist_from_beginning = std::distance(start_search_itr, itr);
                        // Distance from the end.
                        position = search_buffer_size - dist_from_beginning;
                        found = true;
                    }
                    length++;
                    current_lookahead_index++;
                    start_search_itr++; // Increase the start iterator to the next.
                    end_search_itr = start_search_itr + 1; // Assigning the end iterator equals to the next of the start iterator.
                }
                else
                {
                    // The character doesn't exist on the search_buffer so, insert a tuple specifying this
                    // character and break from loop.
                    tuples.push_back(std::make_tuple(position, length, character));

                    // Push the character into the search buffer.
                    search_buffer.push_back(character);

                    // Pop one character from the lookahead_buffer
                    lookahead_buffer.erase(lookahead_buffer.begin());

                    // Pop one character from the lookahead_buffer
                    lookahead_buffer.push_back(payload[cursor+lookahead_buffer_size]);

                    break;
                }
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

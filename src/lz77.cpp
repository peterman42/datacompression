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
    search_buffer.reserve(_search_buffer_size);
    lookahead_buffer.reserve(lookahead_buffer_size);

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
            // 1) Create the tuple and insert it into the 'tuples',
            // 2) Shift forward the search and lookahead buffers
            makeTuplesAndShift( 0
                              , 0
                              , first_char
                              , payload[cursor]);

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
            char character           = 0;
            while(true)
            {
                character = lookahead_buffer[current_lookahead_index];
                auto itr = std::find(start_search_itr, end_search_itr, character);
                if(itr != end_search_itr)
                {
                    if(!found)
                    { // If it's the first time set the position.

                        // Distance from the begining.
                        int32_t dist_from_beginning = std::distance(start_search_itr, itr);
                        // Distance from the end.
                        position = search_buffer_size - dist_from_beginning;
                        found = true;
                    }
                    // Increase length.
                    length++;

                    // Increase the counter pointed to the lookahead buffer.
                    current_lookahead_index++;

                    if(start_search_itr == search_buffer.end()-1)
                    {

                    }
                    else
                    {
                        start_search_itr++;                    // Increase the start iterator to the next.
                        end_search_itr = start_search_itr + 1; // Assigning the end iterator equals to the next of the start iterator.
                    }
                }
                else
                {
                    // 1) Create the tuple and insert it into the 'tuples',
                    // 2) Shift forward the search and lookahead buffers
                    makeTuplesAndShift( position
                                      , length
                                      , character
                                      , payload[cursor]);

                    break;                    
                }

                // Increase cursor one position.
                cursor++;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
bool
LZ77::shiftBuffer( std::vector<char>& buffer
                 , char newEntry
                 , uint32_t maxSize)
{
    bool status = true;
    try
    {
        if(buffer.size() > maxSize)
        {
            // Pop one character from the lookahead_buffer
            buffer.erase(buffer.begin());
        }

        // Push new char.
        buffer.push_back(newEntry);
    }
    catch(...)
    {
        status = false;
    }
    return status;
}

///////////////////////////////////////////////////////////////////////////////
bool
LZ77::makeTuplesAndShift( uint32_t position
                        , uint32_t length
                        , char nextChar
                        , char nextCharInLookAheadBuffer)
{
    bool status = true;
    try
    {
        // The character doesn't exist on the search_buffer so, insert a tuple specifying this
        // character and break from loop.
        tuples.push_back(std::make_tuple(position, length, nextChar));

        // Shift forward the search buffer.
        status = shiftBuffer(search_buffer, nextChar, search_buffer_size);

        if(!status) throw;

        // Shift forward the lookahead buffer.
        status = shiftBuffer(lookahead_buffer, nextCharInLookAheadBuffer, lookahead_buffer_size);
    }
    catch(...)
    {
        status = false;
    }
    return status;
}

///////////////////////////////////////////////////////////////////////////////
std::string
LZ77::decode()
{
    return "";
}

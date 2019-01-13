#include "lz77.h"
#include <iostream>
#include <tuple>
#include <algorithm>

namespace DataCompression { namespace LZ {

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
                              , std::vector<char>({first_char})
                              , std::vector<char>({payload[0]}));
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
            std::vector<char> entriesLookaheadBuffer;
            std::vector<char> entriesSearchBuffer;
            size_t cursorOfNext = search_buffer.size() + lookahead_buffer.size();
            while(true)
            {
                character = lookahead_buffer[current_lookahead_index];

                // Push into the temp buffer the character of lookahead buffer.
                shiftBuffer( entriesSearchBuffer
                           , std::vector<char>({character})
                           , search_buffer_size);

                // Push into the temp buffer the character of payload.
                shiftBuffer( entriesLookaheadBuffer
                           , std::vector<char>({payload[cursorOfNext]})
                           , lookahead_buffer_size);

                cursorOfNext++;

                auto itr = std::find(start_search_itr, end_search_itr, character);
                if(itr != end_search_itr)
                {
                    if(!found)
                    { // If it's the first time set the position.

                        // Distance from the begining.
                        int32_t dist_from_beginning = std::distance(start_search_itr, itr);
                        // Distance from the end.
                        position = search_buffer.size() - dist_from_beginning;
                        found = true;
                    }
                    // Increase length.
                    length++;

                    // Increase the counter pointed to the lookahead buffer.
                    current_lookahead_index++;

                    if(start_search_itr == search_buffer.end()-1)
                    {
                        //start_search_itr = search_buffer.begin();
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
                                      , entriesSearchBuffer
                                      , entriesLookaheadBuffer);

                    break;                    
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
bool
LZ77::shiftBuffer( std::vector<char>& buffer
                 , const std::vector<char>& newEntries
                 , uint32_t maxSize)
{
    bool status = true;
    size_t buffer_len = buffer.size();
    size_t newEntries_len = newEntries.size();
    try
    {
        if(newEntries_len == maxSize)
        { // In case the newEntries size equals with the maxSize then clear the buffer
          // and insert the elements that the newEntries holds.
            buffer.clear();
            buffer.insert(buffer.begin(), newEntries.begin(), newEntries.end());
        }
        else if(newEntries.size() < maxSize)
        {

            if((buffer_len > 0)
                    && (buffer_len < maxSize))
            {
                if(newEntries_len > (maxSize - buffer_len))
                {
                    uint32_t size_removed = 1;
                    if(buffer_len > 0)
                    {
                        // Pop as many characters from buffer in order to insert the newEntries.
                        size_removed = maxSize - newEntries_len;
                    }
                    buffer.erase(buffer.begin(), buffer.begin()+size_removed);
                }
            }
            else if(buffer_len == maxSize)
            {
                uint32_t size_removed = newEntries_len;
                buffer.erase(buffer.begin(), buffer.begin()+size_removed);
            }

            // Push the chars of 'newEntries' on the back of buffer.
            buffer.insert(buffer.end(), newEntries.begin(),newEntries.end());
        }
        else
        {
            throw ("The buffer cannot hold the new entries.");
        }
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
                        , const std::vector<char>& newCharsInSearchBuffer
                        , const std::vector<char>& newCharsInLookAheadBuffer)
{
    bool status = true;
    try
    {
        // The character doesn't exist on the search_buffer so, insert a tuple specifying this
        // character and break from loop.
        tuples.push_back(std::make_tuple(position, length, nextChar));

        // Shift forward the search buffer.
        status = shiftBuffer(search_buffer, newCharsInSearchBuffer, search_buffer_size);

        if(!status) throw;

        // Shift forward the lookahead buffer.
        status = shiftBuffer(lookahead_buffer, newCharsInLookAheadBuffer, lookahead_buffer_size);
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

}}
#ifndef LZ77_H
#define LZ77_H

#include <stdint.h>
#include <string>
#include <map>
#include <vector>

namespace DataCompression { namespace LZ {

class LZ77
{
public:

    std::map<std::string,std::tuple<int,int,std::string>> dictionary;

    ///////////////////////////////////////////////////////////////////////////////
    void encode();

    ///////////////////////////////////////////////////////////////////////////////
    std::string decode();

    LZ77( uint32_t _search_buffer_size
        , uint32_t _lookahead_buffer_size
        , const std::string& _payload);
    ~LZ77() = default;
    LZ77()  = default;
    LZ77(const LZ77& T)            = default;
    LZ77& operator=(const LZ77& T) = default;
    LZ77(LZ77&& T)                 = default;
    LZ77& operator=(LZ77&& T)      = default;
private :

    ///////////////////////////////////////////////////////////////////////////////
    bool shiftBuffer( std::vector<char>& buffer
                    , const std::vector<char>& newEntries
                    , uint32_t maxSize);

    ///////////////////////////////////////////////////////////////////////////////
    bool makeTuplesAndShift( uint32_t position
                           , uint32_t length
                           , char nextChar
                           , const std::vector<char>& newCharsInSearchBuffer
                           , const std::vector<char>& newCharsInLookAheadBuffer);

    uint32_t search_buffer_size;
    uint32_t lookahead_buffer_size;
    std::string payload;
    std::vector<std::tuple<int32_t,uint32_t, char>> tuples;
    std::vector<char> search_buffer;
    std::vector<char> lookahead_buffer;
};

} }
#endif // LZ77_H

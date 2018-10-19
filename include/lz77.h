#ifndef LZ77_H
#define LZ77_H

#include <stdint.h>
#include <string>
#include <map>
#include <list>

class LZ77
{
public:

    std::map<std::string,std::tuple<int,int,std::string>> dictionary;

    ///////////////////////////////////////////////////////////////////////////////
    void compress();

    LZ77( uint32_t _search_buffer_size
        , uint32_t _lookahead_buffer_size
        , std::string _payload);
    ~LZ77() = default;
    LZ77()  = default;
    LZ77(const LZ77& T)            = default;
    LZ77& operator=(const LZ77& T) = default;
    LZ77(LZ77&& T)                 = default;
    LZ77& operator=(LZ77&& T)      = default;
private :
    uint32_t search_buffer_size;
    uint32_t lookahead_buffer_size;
    std::string payload;
    std::list<std::tuple<int32_t,uint32_t, char>> tuples;
    std::list<char> search_buffer;
    std::list<char> lookahead_buffer;
};
#endif // LZ77_H

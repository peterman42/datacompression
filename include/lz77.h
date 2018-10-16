#ifndef LZ77_H
#define LZ77_H

#include <string>

class LZ77
{
public:

    std::string payload;

    ///////////////////////////////////////////////////////////////////////////////
    void compress();

    LZ77(std::string _payload);
    ~LZ77() = default;
    LZ77()  = default;
    LZ77(const LZ77& T)            = default;
    LZ77& operator=(const LZ77& T) = default;
    LZ77(LZ77&& T)                 = default;
    LZ77& operator=(LZ77&& T)      = default;

};
#endif // LZ77_H

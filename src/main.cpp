#include <iostream>
#include "lz77.h"

using namespace DataCompression::LZ;

int main(int argc, char* argv[])
{
    LZ77 encoder(6, 4, argv[1]);
    encoder.encode();

    return 0;
}

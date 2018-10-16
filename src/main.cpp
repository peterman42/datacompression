#include <iostream>
#include "lz77.h"

int main(int argc, char* argv[])
{
    LZ77 encoder(argv[1]);
    encoder.compress();

    return 0;
}

#ifndef HUFFMAN_CODES_H
#define HUFFMAN_CODES_H

#include "commons.h"

namespace DataCompression { namespace Huffman {

class HuffmanCodes
{
public:

   ///////////////////////////////////////////////////////////////////////////////
   static HuffmanCodes& instance();

   huffman_code_map_ptr codes;

private :
    HuffmanCodes();
    HuffmanCodes(const HuffmanCodes& T) = default;
    HuffmanCodes& operator=(const HuffmanCodes& T) = default;
    HuffmanCodes(HuffmanCodes&& T) = default;
    HuffmanCodes& operator=(HuffmanCodes&& T) = default;

};
}}
#endif // HUFFMAN_CODES_H

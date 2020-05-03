#include "huffman_codes.h"

namespace DataCompression { namespace Huffman {

HuffmanCodes::HuffmanCodes()
    : codes(nullptr)
{}

HuffmanCodes& HuffmanCodes::instance()
{
    static auto obj = std::unique_ptr<HuffmanCodes>(new HuffmanCodes());
    return *obj;
}

}}

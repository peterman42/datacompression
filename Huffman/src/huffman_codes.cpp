#include "huffman_codes.h"

namespace DataCompression { namespace Huffman {

HuffmanCodes::HuffmanCodes()
    : codes(std::unique_ptr<huffman_code_map>(new huffman_code_map()))
{}

HuffmanCodes& HuffmanCodes::instance()
{
    static auto obj = std::unique_ptr<HuffmanCodes>(new HuffmanCodes());
    return *obj;
}

}}

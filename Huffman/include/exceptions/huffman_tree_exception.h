#ifndef HUFFMAN_TREE_EXCEPTION_H
#define HUFFMAN_TREE_EXCEPTION_H

#include <exception>

namespace DataCompression { namespace Huffman {

class HuffmanTreeException : public std::runtime_exception
{
public :
    HuffmanTreeException(const std::string& what)
        : std::runtime_exception(what)
    {}
};

} }
#endif // HUFFMAN_TREE_EXCEPTION_H

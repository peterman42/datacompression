#ifndef COMMONS_H
#define COMMONS_H

#include <bitset>
#include <vector>
#include <list>

namespace DataCompression { namespace Huffman {

class Node;
using huffman_code = std::vector<std::bitset<1>>;

///////////////////////////////////////////////////////////////////////////////
std::list<Node> countCharacters (const std::string& text);

}}

#endif

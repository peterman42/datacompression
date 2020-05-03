#ifndef COMMONS_H
#define COMMONS_H

#include <bitset>
#include <vector>
#include <list>

#define MESSAGE_HUFFMAN_TREE_DOES_NOT_EXIST "Huffman Tress does not exist."
#define MESSAGE_PRIORITY_QUEUE_DOES_NOT_CONTAIN "The priority queue should contain one node."

namespace DataCompression { namespace Huffman {

class Node; // forward declaration
using huffman_code = std::vector<std::bitset<1>>;

///////////////////////////////////////////////////////////////////////////////
std::list<Node> countCharacters (const std::string& text);

///////////////////////////////////////////////////////////////////////////////
void sortBufferAsc(std::list<Node>& priority_queue);

}}

#endif

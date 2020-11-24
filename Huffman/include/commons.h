#ifndef COMMONS_H
#define COMMONS_H

#include <bitset>
#include <list>
#include <map>
#include <memory>
#include <vector>

#define MESSAGE_HUFFMAN_TREE_DOES_NOT_EXIST "Huffman Tress does not exist."
#define MESSAGE_PRIORITY_QUEUE_DOES_NOT_CONTAIN "The priority queue should contain one node."

namespace DataCompression { namespace Huffman {

class Node; // forward declaration
using bit = std::bitset<1>;
using huffman_code = std::vector<bit>;
using huffman_code_map = std::map<char, huffman_code>;
using huffman_code_map_ptr = std::unique_ptr<huffman_code_map>;

///////////////////////////////////////////////////////////////////////////////
std::list<Node> countCharacters (const std::vector<char>& text);

///////////////////////////////////////////////////////////////////////////////
void sortBufferAsc(std::list<Node>& priority_queue);

///////////////////////////////////////////////////////////////////////////////
void load_file(const std::string& file_name, std::vector<char>& buffer);

}}

#endif

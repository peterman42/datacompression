#include <huffman.h>
#include <iostream>
#include <algorithm>
#include "exceptions/priority_queue_exception.h"
#include "exceptions/huffman_tree_exception.h"
#include "huffman_codes.h"

namespace DataCompression { namespace Huffman {

///////////////////////////////////////////////////////////////////////////////
void Huffman::encode(const std::string& text)
{

    priority_queue = countCharacters(text);
    sortBufferAsc(priority_queue);

    std::list<Node> priority_queue_clone;
    clonePriorityQueue(priority_queue_clone);

    // Merge the nodes into the priority queue.
    while(priority_queue_clone.size() != 1)
    {
        // Pick the top 2 nodes and merge them.
        mergeNodesWithLessProbability(priority_queue_clone);

        // Sort the buffer again.
        sortBufferAsc(priority_queue_clone);
    }

    if(priority_queue_clone.size() != 1)
        throw PriorityQueueException(MESSAGE_PRIORITY_QUEUE_DOES_NOT_CONTAIN);

    binary_tree.add(priority_queue_clone.front());

}

///////////////////////////////////////////////////////////////////////////////
void Huffman::decode(const std::string& text)
{

}

///////////////////////////////////////////////////////////////////////////////
const huffman_code_map& Huffman::buildCodesMap()
{
    if(!binary_tree.root)
        throw HuffmanTreeException(MESSAGE_HUFFMAN_TREE_DOES_NOT_EXIST);

    // Make a depth-first traverse.
    // During the traverse the codes/weights are set for each node.
    binary_tree.traverse();
    binary_tree.root->createHuffmanCodes();

    return *HuffmanCodes::instance().codes;
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::printPriorityQueue()
{
    for(const auto& node : priority_queue)
    {
        std::cout << node.label << "\t\t|\t\t" << node.value << std::endl;
    }
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::printHuffmanCodes(const huffman_code_map& codes)
{
    for(const auto& pair : codes)
    {
        std::cout << pair.first << " :: "
                  << toString(pair.second)
                  << std::endl;
    }
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::mergeNodesWithLessProbability(std::list<Node>& priority_queue)
{
        auto first_node = priority_queue.front();
        priority_queue.pop_front();
        auto second_node = priority_queue.front();
        priority_queue.pop_front();
        auto new_node = Node( std::make_shared<Node>(first_node)
                            , std::make_shared<Node>(second_node)
                            , first_node.value + second_node.value);
        priority_queue.push_front(new_node);
}

///////////////////////////////////////////////////////////////////////////////
std::string Huffman::toString(const huffman_code& code)
{
    std::string str;
    for(const auto& item : code) {
        str.append(item.to_string());
    }
    return str;
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::clonePriorityQueue(std::list<Node>& clone)
{
    std::copy(priority_queue.begin(),
              priority_queue.end(),
              std::back_inserter(clone));
}

}}

#ifndef PRIORITY_QUEUE_EXCEPTION_H
#define PRIORITY_QUEUE_EXCEPTION_H

#include <exception>

namespace DataCompression { namespace Huffman {

class PriorityQueueException : public std::runtime_error
{
public:
    PriorityQueueException(const std::string& what)
        : std::runtime_error(what)
    {}
};

}}
#endif

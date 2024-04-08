#include "Queue.h"
#include <cstdlib>

template <typename t>
queue<t>::queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {};

template<typename T>
queue<T>::~queue() {
    while (!empty()) {
        pop();
    }
}

template<typename t>
bool queue<t>::empty()
{
    return queueSize == 0;
}

template<typename t>
bool queue<t>::push(const t& value)
{
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = rearNode = newNode;
    }
    else {
        newNode->next_ptr = rearNode;
        rearNode = rearNode->prev_ptr = newNode;
    }
    queueSize += 1;
    return EXIT_SUCCESS;
}

template<typename t>
bool queue<t>::pop()
{
    if (empty())
        return EXIT_FAILURE;
    Node* temp = frontNode;
    frontNode = frontNode->prev_ptr;
    frontNode->next_ptr = nullptr;
    delete temp;
    queueSize -= 1;
    return EXIT_SUCCESS;
}

template<typename t>
t queue<t>::front() 
{
    return frontNode->data;
}

template<typename t>
t queue<t>::rear()
{
    return rearNode->data;
}

template<typename t>
size_t queue<t>::size()
{
    return queueSize;
}

template<typename t>
bool queue<t>::move_to_rear()
{
    if (empty())
        return EXIT_FAILURE;
    push(front());
    pop();
    return EXIT_SUCCESS;
}


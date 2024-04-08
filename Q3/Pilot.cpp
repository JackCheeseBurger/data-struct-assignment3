#include <cstdlib>
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

template<typename T>
void insertionSort(queue<T>& q) {
    queue<T> sortedQueue;
    while (!q.empty()) {
        T current = q.front();
        q.pop();
        while (!sortedQueue.empty() && sortedQueue.rear() > current) {
            q.push(sortedQueue.rear());
            sortedQueue.pop();
        }
        sortedQueue.push(current);
    }
    while (!sortedQueue.empty()) {
        q.push(sortedQueue.front());
        sortedQueue.pop();
    }
}

int main() {

    queue<int> q_int;
    q_int.push(5);
    q_int.push(2);
    q_int.push(4);
    q_int.push(6);
    q_int.push(1);
    q_int.push(3);

    insertionSort(q_int);

    std::cout << "Sorted queue of integers: ";
    while (!q_int.empty()) {
        std::cout << q_int.front() << " ";
        q_int.pop();
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
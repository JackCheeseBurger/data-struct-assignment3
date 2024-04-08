#include <cstdlib>
#include <random>
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

int main() {
	queue<int> Q;
    // Fills the queue with the numbers 1 -> 10.
    for (int i = 0; i < 10; i++) {
        Q.push(i+1);
    }
    // Display Queue Contents
    std::cout << "Displaying Integer Queue: " << std::endl;
    for (int i = 0; i < Q.size(); i++) {
        std::cout << Q.front(); // Print the value
        // Move front to end
        Q.push(Q.front());
        // Pop front
        Q.pop();
        if (i != 9) {
            std::cout << "->";
        }
    }
    std::cout << std::endl << "move_to_rear Test:" << std::endl << "Front: " << Q.front()
        << std::endl << "Rear: " << Q.rear();
    Q.move_to_rear();
    std::cout << std::endl << "Operation Performed" << std::endl << "New-Front: " << Q.front()
        << std::endl << "New-Rear: " << Q.rear();
	return EXIT_SUCCESS;
}
#pragma once
#include <cstdlib>

template <typename t>
class queue {
protected:
	struct Node {
		t data;
		Node *prev_ptr, *next_ptr;
		Node(const t& data) : data(data), next_ptr(nullptr) {}
	};
	Node* frontNode;
	Node* rearNode;
	size_t queueSize;
public:
	// Constructor
	queue();
	// Destrucotr
	~queue();
	// Member Functions
	bool empty();
	bool push(const t& value);
	bool pop();
	t front();
	t rear();
	size_t size();
	bool move_to_rear();
};
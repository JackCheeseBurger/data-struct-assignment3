#pragma once
#include <optional>

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

	bool empty();
public:
	// Constructor
	queue();
	// Destrucotr
	~queue();
	// Member Functions
	bool push(const t& value);
	bool pop();
	t front();
	t rear();
	size_t size();
	bool move_to_rear();
};
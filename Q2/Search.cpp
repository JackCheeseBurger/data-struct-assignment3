#include <iostream>
#include <vector>

using namespace std;

// Template function to find the last occurrence of target in a vector
template<typename T>
int last_occurrence(vector<T>& items, T target, size_t pos_last) {
    // Base case: If pos_last reaches the beginning of the vector, return -1
    if (pos_last == 0)
        return -1;

    // Decrement pos_last to search from the end of the vector
    pos_last--;

    // If the target is found at the current position, return the position
    if (target == items[pos_last])
        return pos_last;
    else
        // Recursively search the previous position
        return last_occurrence(items, target, pos_last);
}

int main() {
    // Test cases with a vector of characters
    vector<char> items = { 'd', 'c', 'x', 'f', 'e', 'd', 'f' };
    char target1 = 'd';
    char target2 = 'z';

    // Find the last occurrence of target1 and target2
    int result1 = last_occurrence(items, target1, items.size());
    int result2 = last_occurrence(items, target2, items.size());

    // Output results
    cout << "Last occurrence of '" << target1 << "' found at position: " << result1 << endl;
    cout << "Last occurrence of '" << target2 << "' found at position: " << result2 << endl;

    return 0;
}
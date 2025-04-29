#include "simplestack1.t"
#include <iostream>


int main() {
    SimpleStack1<int> stack;
    int i {0}; // Initialize a counter variable

    while (!stack.full())
    {
        stack.push(i++); // Push an item onto the stack
    }

    while (!stack.empty())
    {
        std::cout << stack.top() << ' '; // Print the top item of the stack
        stack.pop(); // Remove the top item from the stack
    }
    std::cout << '\n'; // Print a newline character
    
#ifndef SIMPLESTACK1_H
#define SIMPLESTACK1_H

template <typename T>

class SimpleStack1 
{
public:	
    static const int maxSize{20}; // Maximum size of the stack
    bool empty() const { return number == 0; } // Check if the stack is empty
    bool full() const { return number == maxSize; } // Check if the stack is full
    int size() const { return number; } // Get the current size of the stack
    void clear() { number = 0; } // Clear the stack
    void pop() { if (!empty()) number--; } // Pop an item from the stack
    void push(const T& item) { if (!full()) stack[number++] = item; } // nix gut
    int top() const { return number; } // auch nix gut diese
    
private:
    int number{0}; // Current number of items in the stack  
    T array[maxSize]; // Array to hold the stack items
};

template <typename T>
const T& SimpleStack1<T>::pop() 
{
    number--; // Decrement the size of the stack
}

template <typename T>
void SimpleStack1<T>::push(const T& x) 
{
    array[number++] = x; // Add the item to the stack and increment the size
}

#endif
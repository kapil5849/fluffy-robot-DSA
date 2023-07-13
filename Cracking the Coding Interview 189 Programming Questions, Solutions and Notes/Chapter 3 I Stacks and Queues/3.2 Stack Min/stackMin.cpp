#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    // Push an element onto the stack
    void push(int value) {
        dataStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Remove the top element from the stack
    void pop() {
        if (dataStack.empty()) {
            std::cout << "Stack is empty. Cannot perform pop operation." << std::endl;
            return;
        }

        int topElement = dataStack.top();
        dataStack.pop();

        if (topElement == minStack.top()) {
            minStack.pop();
        }
    }

    // Get the top element of the stack
    int top() {
        if (dataStack.empty()) {
            std::cout << "Stack is empty. Cannot perform top operation." << std::endl;
            return -1;
        }

        return dataStack.top();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            std::cout << "Stack is empty. Cannot retrieve minimum element." << std::endl;
            return -1;
        }

        return minStack.top();
    }
};

int main() {
    // Create an instance of the MinStack
    MinStack stack;

    // Push elements onto the stack
    stack.push(5);
    stack.push(2);
    stack.push(7);
    stack.push(1);

    // Get the minimum element
    int minElement = stack.getMin();
    std::cout << "Minimum element: " << minElement << std::endl;  // Output: Minimum element: 1

    // Pop an element from the stack
    stack.pop();

    // Get the top element
    int topElement = stack.top();
    std::cout << "Top element: " << topElement << std::endl;  // Output: Top element: 7

    // Get the updated minimum element
    minElement = stack.getMin();
    std::cout << "Updated minimum element: " << minElement << std::endl;  // Output: Updated minimum element: 2

    return 0;
}

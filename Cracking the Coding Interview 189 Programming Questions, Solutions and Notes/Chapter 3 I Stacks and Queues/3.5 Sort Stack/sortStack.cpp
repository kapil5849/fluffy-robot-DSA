
#include <iostream>
#include <stack>

void sortStack(std::stack<int>& mainStack) {
    std::stack<int> tempStack;

    while (!mainStack.empty()) {
        int temp = mainStack.top();
        mainStack.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    // Transfer elements back to the mainStack (optional)
    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    std::stack<int> stack;

    // Push elements onto the stack
    stack.push(5);
    stack.push(2);
    stack.push(7);
    stack.push(1);

    // Sort the stack
    sortStack(stack);

    // Pop and print the sorted elements
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}
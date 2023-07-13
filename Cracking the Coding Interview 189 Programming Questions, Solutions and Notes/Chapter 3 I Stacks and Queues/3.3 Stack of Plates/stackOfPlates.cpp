// #include <iostream>
// #include <vector>
// #include <stack>

// class SetOfStacks {
// private:
//     std::vector<std::stack<int>> stacks;
//     int capacity;
// public:
//     SetOfStacks(int stackCapacity) : capacity(stackCapacity) {}

//     // Push an element onto the stack
//     void push(int value) {
//         if (stacks.empty() || stacks.back().size() == capacity) {
//             // Create a new stack if the current one is full
//             std::stack<int> newStack;
//             newStack.push(value);
//             stacks.push_back(newStack);
//         } else {
//             // Push the element onto the last stack
//             stacks.back().push(value);
//         }
//     }

//     // Pop the top element from the stack
//     void pop() {
//         if (stacks.empty()) {
//             std::cout << "Stack is empty. Cannot perform pop operation." << std::endl;
//             return;
//         }

//         stacks.back().pop();
//         if (stacks.back().empty()) {
//             // Remove the empty stack
//             stacks.pop_back();
//         }
//     }

//     // Pop an element from a specific sub-stack
//     void popAt(int index) {
//         if (index < 0 || index >= stacks.size()) {
//             std::cout << "Invalid sub-stack index." << std::endl;
//             return;
//         }

//         stacks[index].pop();
//         if (stacks[index].empty()) {
//             // Remove the empty stack
//             stacks.erase(stacks.begin() + index);
//         }
//     }

//     // Get the top element of the stack
//     int top() {
//         if (stacks.empty()) {
//             std::cout << "Stack is empty. Cannot perform top operation." << std::endl;
//             return -1;
//         }

//         return stacks.back().top();
//     }

//     // Check if the stack is empty
//     bool isEmpty() {
//         return stacks.empty();
//     }
// };

// int main() {
//     // Create an instance of SetOfStacks with a capacity of 3
//     SetOfStacks stack(3);

//     // Push elements onto the stack
//     stack.push(5);
//     stack.push(2);
//     stack.push(7);
//     stack.push(1);
//     stack.push(9);
//     stack.push(4);
//     stack.push(3);

//     // Pop an element from the stack
//     stack.pop();

//     // Pop an element from a specific sub-stack
//     stack.popAt(1);

//     // Get the top element
//     int topElement = stack.top();
//     std::cout << "Top element: " << topElement << std::endl;

//     return 0;
// }

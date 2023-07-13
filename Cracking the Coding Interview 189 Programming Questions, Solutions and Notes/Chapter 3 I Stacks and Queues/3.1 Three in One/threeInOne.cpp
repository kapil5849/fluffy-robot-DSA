#include<bits/stdc++.h>
using namespace std;

const int N = 9; // Total size of the array

class ThreeStacks {
private:
    int arr[N]; // Array to store elements
    int top1, top2, top3; // Variables to track top elements of each stack

public:
    ThreeStacks() {
        top1 = -1; // Initialize top of stack 1
        top2 = N / 3 - 1; // Initialize top of stack 2
        top3 = 2 * (N / 3) - 1; // Initialize top of stack 3
    }

    // Push element onto the specified stack
    void push(int stackNum, int value) {
        if (isFull(stackNum)) {
            cout << "Stack overflow!" << endl; // Cannot add element, stack is full
            return;
        }

        if (stackNum == 1)
            arr[++top1] = value; // Increment top1 and add value to stack 1
        else if (stackNum == 2)
            arr[++top2] = value; // Increment top2 and add value to stack 2
        else if (stackNum == 3)
            arr[++top3] = value; // Increment top3 and add value to stack 3
    }

    // Pop element from the specified stack
    void pop(int stackNum) {
        if (isEmpty(stackNum)) {
            cout << "Stack underflow!" << endl; // Cannot remove element, stack is empty
            return;
        }

        if (stackNum == 1)
            top1--; // Decrement top1 to remove element from stack 1
        else if (stackNum == 2)
            top2--; // Decrement top2 to remove element from stack 2
        else if (stackNum == 3)
            top3--; // Decrement top3 to remove element from stack 3
    }

    // Peek at the top element of the specified stack
    int peek(int stackNum) {
        if (isEmpty(stackNum)) {
            cout << "Stack is empty!" << endl; // Stack is empty, cannot peek
            return -1;
        }

        if (stackNum == 1)
            return arr[top1]; // Return top element of stack 1
        else if (stackNum == 2)
            return arr[top2]; // Return top element of stack 2
        else if (stackNum == 3)
            return arr[top3]; // Return top element of stack 3

        return -1; // Invalid stack number
    }

    // Check if the specified stack is empty
    bool isEmpty(int stackNum) {
        if (stackNum == 1 && top1 < 0)
            return true; // Stack 1 is empty
        else if (stackNum == 2 && top2 < N / 3)
            return true; // Stack 2 is empty
        else if (stackNum == 3 && top3 < 2 * (N / 3))
            return true; // Stack 3 is empty

        return false; // Invalid stack number or stack is not empty
    }

    // Check if the specified stack is full
    bool isFull(int stackNum) {
        if (stackNum == 1 && top1 >= N / 3 - 1)
            return true; // Stack 1 is full
        else if (stackNum == 2 && top2 >= 2 * (N / 3) - 1)
            return true; // Stack 2 is full
        else if (stackNum == 3 && top3 >= N - 1)
            return true; // Stack 3 is full

        return false; // Invalid stack number or stack is not full
    }

    // Get the size of the specified stack
    int getSize(int stackNum) {
        if (stackNum == 1)
            return top1 + 1;
        else if (stackNum == 2)
            return top2 - (N / 3) + 1;
        else if (stackNum == 3)
            return top3 - 2 * (N / 3) + 1;

        return 0; // Invalid stack number
    }
};

int main() {
    ThreeStacks stacks;

    stacks.push(1, 5); // Push 5 to stack 1
    stacks.push(2, 10); // Push 10 to stack 2
    stacks.push(3, 15); // Push 15 to stack 3

    cout << stacks.peek(1) << endl; // Output: 5 (top element of stack 1)
    cout << stacks.peek(2) << endl; // Output: 10 (top element of stack 2)
    cout << stacks.peek(3) << endl; // Output: 15 (top element of stack 3)

    stacks.pop(1); // Pop from stack 1

    cout << stacks.peek(1) << endl; // Output: -1 (new top element of stack 1)

    cout << "Size of stack 2: " << stacks.getSize(2) << endl; // Output: 0 (empty stack 2)
    cout << "Is stack 3 empty? " << (stacks.isEmpty(3) ? "Yes" : "No") << endl; // Output: No (stack 3 is not empty)

    return 0;
}

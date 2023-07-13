#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> inbox;   // Used for enqueue operation
    std::stack<int> outbox;  // Used for dequeue operation

public:
    // Enqueue an element to the queue
    void enqueue(int value) {
        inbox.push(value);
    }

    // Dequeue an element from the queue
    int dequeue() {
        if (outbox.empty()) {
            // If outbox is empty, transfer elements from inbox to outbox
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }

        if (outbox.empty()) {
            // If both stacks are empty, the queue is empty
            std::cout << "Queue is empty. Cannot perform dequeue operation." << std::endl;
            return -1;
        }

        int front = outbox.top();
        outbox.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return inbox.empty() && outbox.empty();
    }
};

int main() {
    MyQueue queue;

    // Enqueue elements to the queue
    queue.enqueue(5);
    queue.enqueue(2);
    queue.enqueue(7);

    // Dequeue elements from the queue
    int front = queue.dequeue();
    std::cout << "Dequeued element: " << front << std::endl;

    front = queue.dequeue();
    std::cout << "Dequeued element: " << front << std::endl;

    // Enqueue more elements
    queue.enqueue(9);
    queue.enqueue(1);

    // Dequeue remaining elements
    while (!queue.isEmpty()) {
        front = queue.dequeue();
        std::cout << "Dequeued element: " << front << std::endl;
    }

    return 0;
}
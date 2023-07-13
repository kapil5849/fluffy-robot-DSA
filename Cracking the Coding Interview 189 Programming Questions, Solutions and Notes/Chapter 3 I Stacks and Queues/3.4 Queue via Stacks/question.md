> Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

The problem of implementing a queue using two stacks involves designing a class `MyQueue` that mimics the behavior of a queue data structure using two stacks.




# Steps to solve the problem:

1. Create a class `MyQueue` with two private stacks: `inbox` and `outbox`. `inbox` is used for enqueue operation, while `outbox` is used for dequeue operation.

2. Implement the `enqueue` function to push elements onto the `inbox` stack.

3. Implement the `dequeue` function to remove elements from the queue. If the `outbox` stack is empty, transfer elements from `inbox` to `outbox`. Then, pop the top element from `outbox` and return it as the dequeued element.

4. Implement the `isEmpty` function to check if both `inbox` and `outbox` stacks are empty.

### In the example usage, elements are enqueued and dequeued from the `MyQueue` instance, demonstrating the behavior of a queue implemented using two stacks.
---
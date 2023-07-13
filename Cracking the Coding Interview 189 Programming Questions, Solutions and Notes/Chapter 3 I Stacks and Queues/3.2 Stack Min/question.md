> Stack Min: How would you design a stack which, in addition to push and pop, has a function min 
which returns the minimum element? Push, pop and min should all operate in 0(1) time.


The problem is asking for the design of a stack data structure that supports three operations:

1. Push: Insert an element onto the stack.
2. Pop: Remove and return the top element from the stack.
3. Min: Retrieve the minimum element from the stack.

The key requirement is that all three operations should have a time complexity of O(1), meaning they should execute in constant time regardless of the size of the stack.

To solve this problem, we can use an additional stack, called the "min stack," to keep track of the minimum element at each step. The min stack will store the current minimum element corresponding to the elements pushed onto the main stack.

Steps for solving the problem:

1. Create a class called `MinStack`.
2. Declare two stacks as private members: `mainStack` for storing the elements and `minStack` for storing the minimum elements.
3. Implement the `push` function to add elements to the main stack.
   - Push the element onto the main stack.
   - Check if the element is smaller or equal to the current minimum in the min stack.
   - If it is, push the element onto the min stack as well.
4. Implement the `pop` function to remove elements from the main stack.
   - Check if the element being popped is the current minimum in the min stack.
   - If it is, also remove it from the min stack.
   - Remove the top element from the main stack.
5. Implement the `top` function to return the top element from the main stack.
6. Implement the `getMin` function to return the minimum element from the min stack.
7. Test the implementation to ensure it satisfies the requirements of O(1) time complexity for all three operations.

By following these steps, you can solve the "Stack Min" problem and have a stack data structure that supports push, pop, and min operations in constant time.

In this example, we create an instance of the MinStack class and perform the following operations:

- Push the elements 5, 2, 7, and 1 onto the stack using the push function.
- Retrieve the minimum element from the stack using the getMin function, which returns 1.
- Pop an element from the stack using the pop function.
- Retrieve the top element from the stack using the top function, which returns 7.
- Retrieve the updated minimum element from the stack using the getMin function, which returns 2.
- The MinStack class ensures that the minimum element is always accessible in constant time, even after performing push and pop operations on the stack.

### This code combines the implementation of the MinStack class along with the example usage in the main function. It demonstrates how to push elements onto the stack, retrieve the minimum element, pop an element, get the top element, and retrieve the updated minimum element.
---
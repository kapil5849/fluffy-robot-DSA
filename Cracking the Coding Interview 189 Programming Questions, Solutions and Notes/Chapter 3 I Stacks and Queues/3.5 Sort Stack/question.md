> Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and is Empty. 

The question asks us to implement a program to sort a stack in ascending order, where the smallest items are on the top. We are allowed to use an additional temporary stack, but we cannot copy the elements into any other data structure such as an array. The stack supports the following operations: push, pop, peek, and isEmpty.

# To solve this problem, we can use the following approach:

1. Create two stacks: `mainStack` and `tempStack`.
2. While the `mainStack` is not empty:
   - Pop the top element from the `mainStack` and store it in a variable called `temp`.
   - While the `tempStack` is not empty and the top element of the `tempStack` is greater than `temp`, pop elements from the `tempStack` and push them back to the `mainStack`.
   - Push `temp` onto the `tempStack`.
3. After the above steps, the `tempStack` will contain the sorted stack, with the smallest items on the top.
4. If needed, you can transfer the elements back to the `mainStack` while maintaining the sorted order.

## Explanation:
1. We create a stack called `mainStack` and push the elements onto it: 5, 2, 7, and 1.
2. We call the `sortStack` function, passing `mainStack` as a reference.
3. In the `sortStack` function, we create a temporary stack called `tempStack`.
4. We iterate through `mainStack` until it becomes empty:
   - We pop the top element from `mainStack` and store it in the `temp` variable.
   - We compare `temp` with the elements in `tempStack` and transfer elements from `tempStack` to `mainStack` if they are greater than `temp`.
   - We push `temp` onto `tempStack`.
5. After the sorting is done, we can transfer the elements from `tempStack` back to `mainStack` if needed.
6. Finally, we pop and print the elements from `mainStack`, which are now sorted in ascending order: 1, 2, 5, 7.

### This implementation demonstrates how to sort a stack in-place using an additional temporary stack, ensuring that the smallest items are on the top.
---
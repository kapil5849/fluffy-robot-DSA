> Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop () should return the same values as it would if there were just a single stack). 
FOLLOW UP 
Implement a function popAt ( int index) which performs a pop operation on a specific sub-stack. 

The problem "Stack of Plates" requires implementing a data structure called `SetOfStacks` that behaves like a stack but automatically creates a new stack once the previous stack exceeds a certain capacity. Additionally, a `popAt` function needs to be implemented to perform a pop operation on a specific sub-stack.

- This code implements the `SetOfStacks` class, which internally uses a vector of stacks to store the elements. The `push` operation checks if the last stack is full and creates a new stack if necessary. The `pop` operation removes the top element from the last stack and removes the stack if it becomes empty. The `popAt` operation removes the top element from a specific sub-stack. The `top` operation returns the top element of the last stack, and `isEmpty` checks if the stack is empty.
- Example usage is provided in the `main` function, where elements are pushed onto the stack, popped from the stack, popped from a specific sub-stack, and the top element is retrieved.
--- 
## Step 1: Create an instance of `SetOfStacks` with a capacity of 3
```cpp
SetOfStacks stack(3);
```

## Step 2: Push elements onto the stack
```cpp
stack.push(5);
stack.push(2);
stack.push(7);
stack.push(1);
stack.push(9);
stack.push(4);
stack.push(3);
```
- We push seven elements onto the stack. Since the capacity is 3, when the first sub-stack is full, a new sub-stack is automatically created to accommodate the additional elements.

- The state of the stack after each `push` operation:
```cpp 
Sub-stack 1: 5, 2, 7
Sub-stack 2: 1, 9, 4
Sub-stack 3: 3
```

## Step 3: Pop an element from the stack
```cpp
stack.pop();
```
- We perform a `pop` operation on the stack, which removes the top element from the last sub-stack.

- The state of the stack after the `pop` operation:
```cpp
Sub-stack 1: 5, 2, 7
Sub-stack 2: 1, 9, 4
```

## Step 4: Pop an element from a specific sub-stack
```cpp
stack.popAt(1);
```
- We perform a `popAt` operation on the sub-stack at index 1, which removes the top element from that sub-stack.

- The state of the stack after the `popAt` operation:
```cpp
Sub-stack 1: 5, 2, 7
Sub-stack 2: 1, 9
```

## Step 5: Get the top element of the stack
```cpp
int topElement = stack.top();
std::cout << "Top element: " << topElement << std::endl;
```
- We retrieve the top element of the stack, which is the top element of the last sub-stack.

```cpp
The output:
Top element: 9
```

### In summary, the code implements the `SetOfStacks` class, which allows pushing elements onto the stack, popping elements from the stack, popping elements from specific sub-stacks, getting the top element, and checking if the stack is empty. The capacity of each sub-stack is defined, and when a sub-stack becomes full, a new one is automatically created. This mimics a stack of plates, where a new stack is started when the previous stack exceeds the defined capacity. 
--- 
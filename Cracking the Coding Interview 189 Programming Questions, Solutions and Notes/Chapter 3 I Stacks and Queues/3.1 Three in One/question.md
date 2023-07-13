> Three in One: Describe how you could use a single array to implement three stacks.

To implement three stacks using a single array, you can divide the array into three equal parts and allocate space for each stack within those parts. 

Here's a step-by-step approach to achieving this:
1. Determine the total size of the array and divide it equally by 3 to get the size of each stack. Let's assume the array size is `N`.

2. Create an array of size `N` and initialize three variables to keep track of the top elements of each stack. Let's name these variables `top1`, `top2`, and `top3`, initially set to -1.

3. Define the boundaries for each stack within the array. For example, you can set the first stack's range from index 0 to `(N/3)-1`, the second stack's range from `(N/3)` to `(2*N/3)-1`, and the third stack's range from `(2*N/3)` to `N-1`.

4. To push an element onto any of the stacks, check the corresponding `top` variable to ensure there is space available in that stack. If there is, increment the `top` variable and assign the element to the corresponding index in the array.

5. To pop an element from any of the stacks, check the corresponding `top` variable to ensure there are elements present in that stack. If there are, retrieve the element from the corresponding index in the array and decrement the `top` variable.

6. To peek at the top element of any of the stacks, simply access the element at the corresponding index based on the `top` variable.

### In this implementation, the `ThreeStacks` class maintains three separate top variables for each stack and uses them to access the corresponding portions of the array.
---
- The this keyword in object-oriented programming is used to refer to the current instance of a class. It is mainly used to distinguish between class members and local variables/parameters with the same name.

- Using the this keyword in this example helps to clarify that we are referring to the class members and not local variables or parameters. It ensures that the correct variables are accessed and modified within the class methods.

Benefits of using the this keyword:

- Distinguishing between class members and parameters: In the constructor, using this helps differentiate the class member variables (length and width) from the constructor parameters with the same names. It allows assigning the parameter values to the class members explicitly.

- Accessing class members within methods: In methods like calculateArea(), isSquare(), setDimensions(), and printDimensions(), using this ensures that the correct class members are accessed. It avoids any naming conflicts with local variables or parameters that might have the same names.

- Improved code readability: The use of this makes it clear that we are referring to class members rather than local variables or parameters. It enhances code readability and reduces ambiguity, making the code easier to understand and maintain.

- Facilitating code refactoring: The use of this allows for easy refactoring of code. If you decide to change the naming convention or add additional logic to class members, using this ensures that the references to the members are updated consistently throughout the code.

```cpp
#include <iostream>

class Rectangle {
private:
    int length; // class member...
    int width;  // class member... 

public:
    // Constructor
    Rectangle(int length, int width) {
        // Using "this" to distinguish between class members and parameters
        this->length = length;
        this->width = width;
    }

    // Calculate the area of the rectangle
    int calculateArea() {
        return this->length * this->width;
    }

    // Check if the rectangle is a square
    bool isSquare() {
        // Using "this" to access class members
        if (this->length == this->width) {
            return true;
        } else {
            return false;
        }
    }

    // Set new dimensions for the rectangle
    void setDimensions(int length, int width) {
        // Using "this" to access class members
        this->length = length;
        this->width = width;
    }

    // Print the dimensions of the rectangle
    void printDimensions() {
        // Using "this" to access class members
        std::cout << "Length: " << this->length << std::endl;
        std::cout << "Width: " << this->width << std::endl;
    }
};

int main() {
    Rectangle rectangle(5, 5);

    rectangle.printDimensions();
    std::cout << "Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Is Square? " << (rectangle.isSquare() ? "Yes" : "No") << std::endl;

    rectangle.setDimensions(8, 4);

    rectangle.printDimensions();
    std::cout << "Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Is Square? " << (rectangle.isSquare() ? "Yes" : "No") << std::endl;

    return 0;
}
```
---
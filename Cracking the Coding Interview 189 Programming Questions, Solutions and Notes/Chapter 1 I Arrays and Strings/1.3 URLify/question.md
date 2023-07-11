> URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)
EXAMPLE
```
Input: Mr John Smith      
Output: Mr%20John%20Smith
```

# **Notes :**

## **In-Place Modification**

## **Explanation**

* We first count the number of spaces in the given string by iterating through it.
* Then, we calculate the new length of the string after replacing spaces with '%20' by multiplying the space count by 2 (as each space is replaced by three characters '%20') and adding it to the original length.
* Starting from the end of the original string, we iterate backward and move each character to its new position, replacing spaces with '%20'.
* Finally, we print the modified string as the output.

```cpp
void URLify(char str[], int length) {
    int spaceCount = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    int newLength = length + (spaceCount * 2);
    for (int i = length - 1, j = newLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}
```

> Note: In C++, strings are represented as character arrays, so we can modify the characters in-place without creating a new string.


## **Using an Auxiliary String**

* Traverse the given string character by character.
* Whenever a space is encountered, append "%20" to the auxiliary string.
* If a non-space character is encountered, simply append the character to the auxiliary string.
* After traversing the entire string, copy the characters from the auxiliary string back to the original string.
* Return the modified string.

```cpp
string URLify(string str, int length) {
    string aux;

    // Traverse the given string character by character
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            // Append "%20" to the auxiliary string
            aux += "%20";
        } else {
            // Append the character to the auxiliary string
            aux += str[i];
        }
    }

    // Copy characters from the auxiliary string back to the original string
    for (int i = 0; i < aux.length(); i++) {
        str[i] = aux[i];
    }

    return str;
}
```

Here's a table summarizing the time and space complexity of the two approaches mentioned for the URLify problem:

| Approach                        | Time Complexity                  | Space Complexity   |
| ------------------------------- | -------------------------------- | ------------------ |
| Using an Auxiliary String       | O(N)                             | O(N)               |
| In-Place Modification           | O(N)                             | O(1)               |

In the table:
- N represents the length of the given string.

For the "Using an Auxiliary String" approach:
- Time Complexity: The time complexity is O(N) because we traverse the given string once, resulting in linear time complexity.
- Space Complexity: The space complexity is O(N) because we use an auxiliary string to store the modified characters. The size of the auxiliary string is proportional to the length of the input string.

For the "In-Place Modification" approach:
- Time Complexity: The time complexity is O(N) because we traverse the given string once to count spaces and once again to perform in-place modifications. Both traversals are linear in terms of the length of the input string.
- Space Complexity: The space complexity is O(1) because we modify the original string in-place without using any extra space. We only use a constant amount of additional space to store the count of spaces and a few variables for indices and iterations.

In terms of both time and space complexity, the "In-Place Modification" approach has better efficiency, as it does not require additional space.


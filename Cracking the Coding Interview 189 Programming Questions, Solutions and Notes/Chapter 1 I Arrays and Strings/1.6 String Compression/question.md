> String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).
# Notes
## **Counting and Appending**
- Initialize an empty string variable to store the compressed string.
- Initialize a count variable to 1 to keep track of the number of occurrences of each character.
- Iterate through the input string from the second character to the end.
- Compare each character with the previous character.
- If the current character is the same as the previous character, increment the count.
- If the current character is different from the previous character, do the following:
   - Append the previous character to the compressed string.
   - Append the count of occurrences of the previous character to the compressed string.
   - Reset the count to 1.
   - After the loop ends, append the last character and its count to the compressed string.
   - Check if the length of the compressed string is shorter than the original string.
   - If the compressed string is shorter, return the compressed string.
- If the compressed string is not shorter, return the original string.
```cpp
string compressString_CountAndAppend(const string& str) {
    int length = str.length();
    if (length <= 1) {
        return str;
    }
    string compressed;
    int count = 1;
    for (int i = 1; i < length; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            compressed += str[i - 1] + to_string(count);
            count = 1;
        }
    }
    compressed += str[length - 1] + to_string(count);
    if (compressed.length() >= length) {
        return str;
    }
    return compressed;
}
```
## **Two-Pointers**
- Initialize an empty string variable to store the compressed string.
- Initialize two pointers, `i` and `j`, to iterate through the input string.
- Set `i` to 0 and `j` to 1.
- Iterate while `j` is less than or equal to the length of the string.
- If the character at index `j` is the same as the character at index `i`, increment `j`.
- If the character at index `j` is different from the character at index `i`, do the following:
   - Append the character at index `i` to the compressed string.
   - Append the count of occurrences from `i` to `j-1` to the compressed string.
   - Set `i` to `j` and increment `j`.
- After the loop ends, append the last character and its count to the compressed string.
- Check if the length of the compressed string is shorter than the original string.
- If the compressed string is shorter, return the compressed string.
- If the compressed string is not shorter, return the original string.
```cpp
string compressString_TwoPointers(const string& str) {
    int length = str.length();
    if (length <= 1) {
        return str;
    }
    string compressed;
    int count = 1;
    for (int i = 0, j = 1; j <= length; j++) {
        if (j < length && str[j] == str[i]) {
            count++;
        } else {
            compressed += str[i] + to_string(count);
            i = j;
            count = 1;
        }
    }
    if (compressed.length() >= length) {
        return str;
    }
    return compressed;
}
```
## **In-Place Compression**
- Initialize a write index variable to keep track of the position to write the next character in the input string.
- Initialize a count variable to 1 to keep track of the number of occurrences of each character.
- Initialize a previous character variable and set it to the first character of the input string.
- Iterate through the input string from the second character to the end.
- If the current character is the same as the previous character, increment the count.
- If the current character is different from the previous character, do the following:
   - Update the input string in-place by writing the previous character at the write index.
   - Convert the count to a string and write each digit at the write index.
   - Update the write index accordingly.
   - Reset the count to 1.
   - Update the previous character to the current character.
- After the loop ends, update the input string in-place with the last character and its count.
- Convert the count to a string and write each digit at the write index.
- Erase the remaining characters from the input string starting from the write index + 1 to truncate it.
- No explicit return statement is needed as the modifications are made directly to the input string.
```cpp
void compressStringInPlace(string& str) {
    int length = str.length();
    if (length <= 1) {
        return;
    }
    string compressed;
    int count = 1;
    char previousChar = str[0];
    for (int i = 1; i < length; i++) {
        if (str[i] == previousChar) {
            count++;
        } else {
            compressed += previousChar + to_string(count);
            count = 1;
            previousChar = str[i];
        }
    }
    compressed += previousChar + to_string(count);
    if (compressed.length() < length) {
        str = compressed;
    }
    return;
}
```
## **Time and Space Complexity**
| Approach                   | Time Complexity                  | Space Complexity  |
|----------------------------|----------------------------------|-------------------|
| Counting and Appending     | O(n)                             | O(n)              |
| Two-Pointers               | O(n)                             | O(n)              |
| In-Place Compression       | O(n)                             | O(1)              |

### Note:

- `n` refers to the length of the input string.
- The space complexity for all approaches is considered based on the additional space required to store the compressed string (if it is shorter than the original string) or the output string.

The time complexity for all approaches is linear, as each approach iterates through the input string once.

The space complexity for the Counting and Appending and Two-Pointers approaches is O(n) because they require additional space to store the compressed string. In the worst case, the compressed string can be as long as the input string, resulting in O(n) space complexity.

The space complexity for the In-Place Compression approach is O(1) because it modifies the input string in-place without requiring additional space for the compressed string.

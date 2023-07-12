> One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
EXAMPLE : 
```
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false
```
## **Character Comparison**
- Compare the lengths of the two strings, denoted as `length1` and `length2`. If the absolute difference between the lengths is greater than 1, return false immediately, as more than one edit is required to make the strings identical.
- Initialize two pointers, `index1` and `index2`, to track the positions in the strings. Start both pointers at the beginning of their respective strings.
- Initialize a boolean variable, `foundDifference`, to track whether a difference between the strings has been found.
- Traverse the strings character by character, incrementing the pointers:
   - If the characters at the current positions are different, perform the following checks:
     - If a difference has already been found (`foundDifference` is true), return false. This indicates that more than one edit is required.
     - If the lengths of the strings are equal (`length1 == length2`), move both pointers ahead by one position to simulate a replacement edit.
     - If `length1` is smaller than `length2`, move only the pointer in the second string (`index2`) ahead by one position to simulate an insertion edit.
     - If `length1` is greater than `length2`, move only the pointer in the first string (`index1`) ahead by one position to simulate a removal edit.
     - Set `foundDifference` to true to indicate that a difference has been found.
- After traversing the strings, if `foundDifference` is true, return true. This indicates that only one edit was required to make the strings identical.
- If `foundDifference` is false, return true only if the lengths of the strings differ by exactly one. This accounts for the case where an insertion or removal edit is needed.
```cpp
bool isOneEditAway(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    if (abs(length1 - length2) > 1) {
        return false;
    }
    int index1 = 0;
    int index2 = 0;
    bool foundDifference = false;
    while (index1 < length1 && index2 < length2) {
        if (str1[index1] != str2[index2]) {
            if (foundDifference) {
                return false;
            }
            if (length1 == length2) {
                index1++;
                index2++;
            } else if (length1 < length2) {
                index2++;
            } else {
                index1++;
            }
            foundDifference = true;
        } else {
            index1++;
            index2++;
        }
    }
    return foundDifference || (index1 < length1) || (index2 < length2);
}
```
## **Frequency Count**
Certainly! Here are the steps for the 2nd approach (Frequency Count) and the 3rd approach (Bit Manipulation) to solve the "One Away" problem:

Approach 2: Frequency Count

- Compare the lengths of the two strings, denoted as `length1` and `length2`. If the absolute difference between the lengths is greater than 1, return false immediately, as more than one edit is required to make the strings identical.
- Initialize two frequency arrays, `frequency1` and `frequency2`, of size 26 (assuming lowercase alphabets only), with all elements initialized to zero.
- Traverse the first string, `str1`, character by character.
- For each character encountered, update its frequency in `frequency1` by incrementing the corresponding index (`c - 'a'`), where `c` is the current character.
- Traverse the second string, `str2`, character by character.
- For each character encountered, update its frequency in `frequency2` by incrementing the corresponding index (`c - 'a'`), where `c` is the current character.
- Initialize a variable, `differenceCount`, to track the number of differences between the frequencies of characters in `frequency1` and `frequency2`.
- Compare the frequencies of characters in `frequency1` and `frequency2`:
   - For each index `i` from 0 to 25, check if `frequency1[i]` is not equal to `frequency2[i]`.
   - If the frequencies are different, increment `differenceCount` by 1.
   - If `differenceCount` exceeds 1, return false, as more than one edit is required to make the strings identical.
- After comparing the frequencies of characters, return true if `differenceCount` is at most 1, indicating that the strings are one edit (or zero edits) away from each other.
```cpp
bool isOneEditAway(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    if (abs(length1 - length2) > 1) {
        return false;
    }
    int frequency1[26] = {0};
    int frequency2[26] = {0};
    for (char c : str1) {
        frequency1[c - 'a']++;
    }
    for (char c : str2) {
        frequency2[c - 'a']++;
    }
    int differenceCount = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency1[i] != frequency2[i]) {
            differenceCount++;
        }
        if (differenceCount > 1) {
            return false;
        }
    }
    return true;
}
```
## **Bit Manipulation**
- Compare the lengths of the two strings, denoted as `length1` and `length2`. If the absolute difference between the lengths is greater than 1, return false immediately, as more than one edit is required to make the strings identical.
- Initialize a bitmask variable, `bitmask`, to 0.
- Traverse the first string, `str1`, character by character.
- For each character encountered, calculate the position of the bit using the character's ASCII value (`c - 'a'`), where `c` is the current character.
- Toggle the corresponding bit in the bitmask by performing the XOR (^) operation with `1` shifted left by the bit position.
   - If the bit is set, the XOR operation will clear it.
   - If the bit is clear, the XOR operation will set it.
- Traverse the second string, `str2`, character by character.
- For each character encountered, calculate the position of the bit using the character's ASCII value (`c - 'a'`), where `c` is the current character.
- Toggle the corresponding bit in the bitmask by performing the XOR (^) operation with `1` shifted left by the bit position.
- After traversing both strings, check if the bitmask has at most one bit set:
   - Apply the logical AND (&) operation between the bitmask and the bitmask decremented by one (`bitmask & (bitmask - 1)`).
   - If the result is zero, it means the bitmask has at most one bit set, indicating a permutation of a palindrome.
   - If the result is non-zero, it means the bitmask has more than one bit set, indicating that it does not satisfy the conditions for a permutation of a palindrome.
- Return true if the bitmask has at most one bit set, indicating that the strings are one edit (or zero edits) away from each other. Otherwise, return false.
```cpp
bool isOneEditAway(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    if (abs(length1 - length2) > 1) {
        return false;
    }
    int bitmask = 0;
    for (char c : str1) {
        bitmask ^= (1 << (c - 'a'));
    }
    for (char c : str2) {
        bitmask ^= (1 << (c - 'a'));
    }
    return (bitmask & (bitmask - 1)) == 0;
}
```
## **Time and Space Complexity**

| Approach                 | Time Complexity       | Space Complexity      |
| ------------------------ | --------------------- | --------------------- |
| Character Comparison     | O(N)                  | O(1)                  |
| Frequency Count          | O(N)                  | O(1)                  |
| Bit Manipulation         | O(N)                  | O(1)                  |

In the table:
- "N" represents the length of the longer string between the two input strings.
- Time complexity refers to the amount of time required to execute the algorithm as a function of the input size.
- Space complexity refers to the amount of additional memory required by the algorithm as a function of the input size.

For the Character Comparison and Frequency Count approaches, the time complexity is O(N) because we traverse the strings character by character once. The space complexity is O(1) because we use a fixed-size array to store the character frequencies, and the size of the array remains constant regardless of the input size.

For the Bit Manipulation approach, the time complexity is also O(N) because we traverse the strings character by character once. The space complexity is O(1) because we only use a single integer variable (`bitmask`) to store the bits, and the space used is constant regardless of the input size.

Overall, all three approaches have linear time complexity and constant space complexity, making them efficient for solving the "One Away" problem.
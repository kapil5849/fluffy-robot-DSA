> Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE

```
Input: Tact Coa
Output: True (permutations: "taco cat", "atco eta", etc.)
```

#### To check if a given string is a permutation of a palindrome, we can utilize the property of a palindrome: it reads the same forwards and backwards. Therefore, any permutation of a palindrome will have the same characters occurring an even number of times, except possibly one character in the middle.

## **Frequency Map Approach** 

* Convert the input string to lowercase and remove any spaces.
* Initialize a frequency map to count the occurrences of each character in the modified string.
* Traverse the modified string character by character and update the frequency map.
* Count the number of characters that have an odd frequency.
* If the count of odd frequency characters is at most one, return true (as it indicates a permutation of a palindrome). Otherwise, return false.

```cpp
bool isPermutationOfPalindrome(const string& str) {
    string modifiedStr;
    for (char c : str) {
        if (isalpha(c)) {
            modifiedStr += tolower(c);
        }
    }
    unordered_map<char, int> frequencyMap;
    for (char c : modifiedStr) {
        frequencyMap[c]++;
    }
    int oddFrequencyCount = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second % 2 != 0) {
            oddFrequencyCount++;
        }
    }
    return oddFrequencyCount <= 1;
}
```

## **Using Set**
- Convert the input string to lowercase and remove any spaces.
- Initialize an empty set to keep track of characters seen so far.
- Traverse the modified string character by character.
- If a character is already in the set, remove it from the set.
- If a character is not in the set, add it to the set.
- After traversing the string, check if the set contains at most one character. If so, return true; otherwise, return false.

This approach uses a set to keep track of characters encountered. If a character is seen more than once, it is removed from the set. At the end, the set should contain at most one character if the string is a permutation of a palindrome.

```cpp
bool isPermutationOfPalindrome(const string& str) {
    string modifiedStr;
    for (char c : str) {
        if (isalpha(c)) {
            modifiedStr += tolower(c);
        }
    }
    unordered_set<char> charSet;
    for (char c : modifiedStr) {
        if (charSet.count(c) > 0) {
            charSet.erase(c);
        } 
        else {
            charSet.insert(c);
        }
    }
    return charSet.size() <= 1;
}
```

## **Using Array**
- Convert the input string to lowercase and remove any spaces.
- Initialize an array of size 26 to represent the frequencies of characters (assuming the string contains only lowercase alphabets).
- Traverse the modified string character by character.
- Increment the frequency of each character in the array.
- Count the number of characters that have an odd frequency.
- If the count of odd frequency characters is at most one, return true; otherwise, return false.

This approach uses an array to keep track of character frequencies. At the end, we check the count of odd frequency characters to determine if the string is a permutation of a palindrome.

```cpp
bool isPermutationOfPalindrome(const string& str) {
    string modifiedStr;
    for (char c : str) {
        if (isalpha(c)) {
            modifiedStr += tolower(c);
        }
    }
    int frequency[26] = {0};
    for (char c : modifiedStr) {
        frequency[c - 'a']++;
    }
    int oddFrequencyCount = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] % 2 != 0) {
            oddFrequencyCount++;
        }
    }
    return oddFrequencyCount <= 1;
}
```

## **Using Bit Manipulation**
- Convert the input string to lowercase and remove any spaces.
- Initialize a bitmask variable.
- Traverse the modified string character by character.
- Toggle the bit representing each character in the bitmask.
- After traversing the string, check if the bitmask has at most one bit set. If so, return true; otherwise, return false.

This approach utilizes bit manipulation to keep track of characters encountered. We toggle the corresponding bit in the bitmask as we traverse the string. At the end, we check if the bitmask has at most one bit set, indicating a permutation of a palindrome.

```cpp
bool isPermutationOfPalindrome(const string& str) {
    string modifiedStr;
    for (char c : str) {
        if (isalpha(c)) {
            modifiedStr += tolower(c);
        }
    }
    int bitmask = 0;
    for (char c : modifiedStr) {
        bitmask ^= (1 << (c - 'a'));
    }
    return (bitmask & (bitmask - 1)) == 0;
}
```

The Time and Space Complexity for Palindrome Permutation problem:

| Approach                  | Time Complexity       | Space Complexity   |
| ------------------------- | --------------------- | ------------------ |
| Frequency Map             | O(N)                  | O(N)               |
| Set                       | O(N)                  | O(N)               |
| Array                     | O(N)                  | O(1)               |
| Bit Manipulation          | O(N)                  | O(1)               |

In the table:
- N represents the length of the input string.

For all the approaches, the time complexity is O(N) because we need to traverse the input string character by character. The space complexity varies based on the approach:

- Frequency Map: The space complexity is O(N) because we use a frequency map (unordered_map or array) to store the character frequencies, which can grow linearly with the size of the input string.
- Set: The space complexity is O(N) because we use a set to track the unique characters encountered, which can grow linearly with the size of the input string.
- Array: The space complexity is O(1) because we use a fixed-size array of length 26 (assuming lowercase alphabets only) to track the character frequencies.
- Bit Manipulation: The space complexity is O(1) because we use a single bitmask variable to track the character occurrences using bitwise operations.

In terms of both time and space complexity, the Bit Manipulation approach has the most efficient performance, as it requires constant space without using any additional data structures. However, all four approaches provide viable solutions to determine if a string is a permutation of a palindrome, and the choice of approach may depend on factors such as the constraints of the problem or the available resources.

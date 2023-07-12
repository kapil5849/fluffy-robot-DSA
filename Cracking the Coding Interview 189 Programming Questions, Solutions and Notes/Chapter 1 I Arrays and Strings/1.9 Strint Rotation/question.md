> String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
# Notes
## **Concatenation and Substring Check**
- Check if the lengths of the two strings are equal. If they are not equal, return false as a rotation is not possible.
- Concatenate the first string with itself, forming a new string.
- Check if the second string is a substring of the concatenated string. If it is a substring, then it is a rotation of the first string; otherwise, it is not.
```cpp
bool isRotation_Concatenation(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    string concatenated = str1 + str1;
    return concatenated.find(str2) != string::npos;
}
```
## **Check Circular Shifts**
- Check if the lengths of the two strings are equal. If they are not equal, return false as a rotation is not possible.
- Perform circular shifts on the first string by moving the last character to the front in each iteration.
- Check if any of the circularly shifted strings match the second string. If a match is found, then the second string is a rotation of the first string; otherwise, it is not.
```cpp
bool isRotation_CircularShifts(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    int n = str1.length();
    for (int i = 0; i < n; i++) {
        string shifted = str1.substr(n - i) + str1.substr(0, n - i);
        if (shifted == str2) {
            return true;
        }
    }
    return false;
}
```
## **Compare Sorted Strings**
- Check if the lengths of the two strings are equal. If they are not equal, return false as a rotation is not possible.
- Sort the characters in both strings in ascending order.
- Compare the sorted strings. If they are equal, then the second string is a rotation of the first string; otherwise, it is not.
```cpp
bool isRotation_SortedStrings(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    string sortedStr1 = str1;
    string sortedStr2 = str2;
    sort(sortedStr1.begin(), sortedStr1.end());
    sort(sortedStr2.begin(), sortedStr2.end());
    return sortedStr1 == sortedStr2;
}
```
## **Time and Space Complexity**

| Approach                           | Time Complexity      | Space Complexity     |
|------------------------------------|----------------------|----------------------|
| Concatenation and Substring Check  | O(N)                 | O(N)                 |
| Check Circular Shifts              | O(N^2)               | O(N)                 |
| Compare Sorted Strings             | O(NlogN)             | O(N)                 |

In the table above, N represents the length of the strings. The time complexity is given in terms of the length of the strings, and the space complexity is indicated as the additional space used by the algorithm.

- Approach 1 (Concatenation and Substring Check) has a time complexity of O(N) as it involves creating a concatenated string and performing a substring check. The space complexity is O(N) as it requires additional space for the concatenated string.

- Approach 2 (Check Circular Shifts) has a time complexity of O(N^2) as it involves iterating through the circular shifts and comparing them with the second string. The space complexity is O(N) as it requires additional space for each circular shift.

- Approach 3 (Compare Sorted Strings) has a time complexity of O(NlogN) as it involves sorting the strings and then comparing them. The space complexity is O(N) as it requires additional space for the sorted strings.


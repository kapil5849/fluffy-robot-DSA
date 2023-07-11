> Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

# **Notes :**

## **Brute Force Approach**

The brute force approach is the simplest approach to determine if two strings are permutations of each other. It simply iterates through the first string and checks if each character is in the second string. If all the characters in the first string are in the second string, then the two strings are permutations of each other.

```c++
bool is_permutation_brute_force(const string& str1, const string& str2) {
  // Check if the two strings have the same length.
  if (str1.length() != str2.length()) {
    return false;
  }

  // Iterate through str1 and check if each character is in str2.
  for (char c : str1) {
    if (str2.find(c) == string::npos) {
      return false;
    }
  }

  // If we reach the end of str1 and all the characters are in str2, then the two strings are permutations of each other.
  return true;
}
```

Time Complexity : O(n^2)

Space Complexity : O(1)

# **Sort both strings and then compare them approach**

The Sort both strings and then compare them approach is a more efficient approach to determine if two strings are permutations of each other. It first sorts both strings in ascending order. Then, it compares the two strings character by character. If the two strings are permutations of each other, then the sorted strings will be the same.

```c++
bool is_permutation_sort(const string& str1, const string& str2) {
  // Sort both strings.
  string sorted_str1 = str1;
  string sorted_str2 = str2;
  sort(sorted_str1.begin(), sorted_str1.end());
  sort(sorted_str2.begin(), sorted_str2.end());

  // Compare the sorted strings character by character.
  for (int i = 0; i < sorted_str1.length(); i++) {
    if (sorted_str1[i] != sorted_str2[i]) {
      return false;
    }
  }

  // If we reach the end of the sorted strings and all the characters are the same, then the two strings are permutations of each other.
  return true;
}
```

Time Complexity: O(n log n)

Space Complexity: O(n)

# **Hash Table Approach**

The hash table approach is the most efficient approach to determine if two strings are permutations of each other. It uses a hash table to store the characters in the first string. The hash table is then used to check if each character in the second string is in the hash table.

```c++
bool is_permutation(const string& str1, const string& str2) {
  // Check if the two strings have the same length.
  if (str1.length() != str2.length()) {
    return false;
  }

  // Create a hash table to store the characters in str1.
  unordered_map<char, int> char_map;
  for (char c : str1) {
    char_map[c]++;
  }

  // Iterate through str2 and check if each character is in the hash table.
  for (char c : str2) {
    if (char_map.find(c) == char_map.end()) {
      return false;
    } else {
      char_map[c]--;
    }
  }

  // If we reach the end of str2 and all the characters are in the hash table, then the two strings are permutations of each other.
  for (auto it = char_map.begin(); it != char_map.end(); it++) {
    if (it->second != 0) {
      return false;
    }
  }

  return true;
}
```

Time Complexity : O(n)

Space Complexity : O(n)

# **Notes for revision** 

* The brute force approach is the simplest approach, but it is also the least efficient.
* The Sort both strings and then compare them approach is more efficient than the brute force approach, but it is still not as efficient as the hash table approach.
* The hash table approach is the most efficient approach, but it requires more space than the other two approaches.

**Table for complexity:**

| Approach | Time complexity | Space complexity |
|---|---|---|
| Brute force | O(n^2) | O(1) |
| Sort both strings and then compare them | O(n log n) | O(n) |
| Hash table | O(n) | O(n) |

#include <iostream>
#include <string>

using namespace std;

// Brute force approach
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

// Sort both strings and then compare them
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

// Hash table approach
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

int main() {
  string str1 = "hello";
  string str2 = "olleh";

  // Check if the two strings are permutations of each other using the brute force approach.
  if (is_permutation_brute_force(str1, str2)) {
    cout << "The two strings are permutations of each other using the brute force approach." << endl;
  } else {
    cout << "The two strings are not permutations of each other using the brute force approach." << endl;
  }

  // Check if the two strings are permutations of each other using the sort approach.
  if (is_permutation_sort(str1, str2)) {
    cout << "The two strings are permutations of each other using the sort approach." << endl;
  } else {
    cout << "The two strings are not permutations of each other using the sort approach." << endl;
  }

  // Check if the two strings are permutations of each other using the hash table approach.
  if (is_permutation(str1, str2)) {
    cout << "The two strings are permutations of each other using the hash table approach." << endl;
  } else {
    cout << "The two strings are not permutations of each other using the hash table approach." << endl;
  }

  return 0;
}

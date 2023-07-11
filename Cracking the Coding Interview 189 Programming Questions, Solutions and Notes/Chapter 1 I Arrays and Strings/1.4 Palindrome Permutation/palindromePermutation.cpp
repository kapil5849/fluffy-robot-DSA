#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPermutationOfPalindrome(const string& str) {
    string modifiedStr;

    // Convert the string to lowercase and remove spaces
    for (char c : str) {
        if (isalpha(c)) {
            modifiedStr += tolower(c);
        }
    }

    unordered_map<char, int> frequencyMap;

    // Count the occurrences of each character in the modified string
    for (char c : modifiedStr) {
        frequencyMap[c]++;
    }

    int oddFrequencyCount = 0;

    // Count the number of characters with odd frequencies
    for (const auto& pair : frequencyMap) {
        if (pair.second % 2 != 0) {
            oddFrequencyCount++;
        }
    }

    // Check if the count of odd frequency characters is at most one
    return oddFrequencyCount <= 1;
}

int main() {
    string str = "Tact Coa";

    cout << "Input: " << str << endl;

    // Call the function to check if the string is a permutation of a palindrome
    bool isPermutation = isPermutationOfPalindrome(str);

    cout << "Output: " << (isPermutation ? "True" : "False") << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// #include <unordered_set>

// using namespace std;

// bool isPermutationOfPalindrome(const string& str) {
//     string modifiedStr;

//     // Convert the string to lowercase and remove spaces
//     for (char c : str) {
//         if (isalpha(c)) {
//             modifiedStr += tolower(c);
//         }
//     }

//     unordered_set<char> charSet;

//     // Traverse the modified string character by character
//     for (char c : modifiedStr) {
//         // If character is already in the set, remove it
//         if (charSet.count(c) > 0) {
//             charSet.erase(c);
//         } 
//         // If character is not in the set, add it
//         else {
//             charSet.insert(c);
//         }
//     }

//     // Check if the set contains at most one character
//     return charSet.size() <= 1;
// }

// int main() {
//     string str = "Tact Coa";

//     cout << "Input: " << str << endl;

//     // Call the function to check if the string is a permutation of a palindrome
//     bool isPermutation = isPermutationOfPalindrome(str);

//     cout << "Output: " << (isPermutation ? "True" : "False") << endl;

//     return 0;
// }


// #include <iostream>
// #include <string>

// using namespace std;

// bool isPermutationOfPalindrome(const string& str) {
//     string modifiedStr;

//     // Convert the string to lowercase and remove spaces
//     for (char c : str) {
//         if (isalpha(c)) {
//             modifiedStr += tolower(c);
//         }
//     }

//     int frequency[26] = {0};

//     // Traverse the modified string character by character
//     for (char c : modifiedStr) {
//         frequency[c - 'a']++;
//     }

//     int oddFrequencyCount = 0;

//     // Count the number of characters with odd frequencies
//     for (int i = 0; i < 26; i++) {
//         if (frequency[i] % 2 != 0) {
//             oddFrequencyCount++;
//         }
//     }

//     // Check if the count of odd frequency characters is at most one
//     return oddFrequencyCount <= 1;
// }

// int main() {
//     string str = "Tact Coa";

//     cout << "Input: " << str << endl;

//     // Call the function to check if the string is a permutation of a palindrome
//     bool isPermutation = isPermutationOfPalindrome(str);

//     cout << "Output: " << (isPermutation ? "True" : "False") << endl;

//     return 0;
// }


// #include <iostream>
// #include <string>

// using namespace std;

// bool isPermutationOfPalindrome(const string& str) {
//     string modifiedStr;

//     // Convert the string to lowercase and remove spaces
//     for (char c : str) {
//         if (isalpha(c)) {
//             modifiedStr += tolower(c);
//         }
//     }

//     int bitmask = 0;

//     // Traverse the modified string character by character
//     for (char c : modifiedStr) {
//         // Toggle the bit representing the character
//         bitmask ^= (1 << (c - 'a'));
//     }

//     // Check if the bitmask has at most one bit set
//     return (bitmask & (bitmask - 1)) == 0;
// }

// int main() {
//     string str = "Tact Coa";

//     cout << "Input: " << str << endl;

//     // Call the function to check if the string is a permutation of a palindrome
//     bool isPermutation = isPermutationOfPalindrome(str);

//     cout << "Output: " << (isPermutation ? "True" : "False") << endl;

//     return 0;
// }


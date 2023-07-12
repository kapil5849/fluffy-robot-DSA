#include <iostream>
#include <string>

using namespace std;

// Approach 1: Character Comparison
bool isOneEditAway_CharacterComparison(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();

    // Check the absolute difference in lengths
    if (abs(length1 - length2) > 1) {
        return false;
    }

    int index1 = 0;
    int index2 = 0;
    bool foundDifference = false;

    while (index1 < length1 && index2 < length2) {
        if (str1[index1] != str2[index2]) {
            // Check if a difference has already been found
            if (foundDifference) {
                return false;
            }

            // Perform the appropriate edit based on string lengths
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

    // Check if a difference was found or if lengths differ by exactly one
    return foundDifference || (index1 < length1) || (index2 < length2);
}

// Approach 2: Frequency Count
bool isOneEditAway_FrequencyCount(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();

    // Check the absolute difference in lengths
    if (abs(length1 - length2) > 1) {
        return false;
    }

    int frequency1[26] = {0};
    int frequency2[26] = {0};

    // Count the frequencies of characters in str1
    for (char c : str1) {
        frequency1[c - 'a']++;
    }

    // Count the frequencies of characters in str2
    for (char c : str2) {
        frequency2[c - 'a']++;
    }

    int differenceCount = 0;

    // Compare the frequencies of characters
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

// Approach 3: Bit Manipulation
bool isOneEditAway_BitManipulation(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();

    // Check the absolute difference in lengths
    if (abs(length1 - length2) > 1) {
        return false;
    }

    int bitmask = 0;

    // Update the bitmask using characters from str1
    for (char c : str1) {
        bitmask ^= (1 << (c - 'a'));
    }

    // Update the bitmask using characters from str2
    for (char c : str2) {
        bitmask ^= (1 << (c - 'a'));
    }

    // Check if the bitmask has at most two bits set
    return (bitmask & (bitmask - 1)) == 0;
}

int main() {
    string str1 = "pale";
    string str2 = "bake";

    cout << "Input: " << str1 << ", " << str2 << endl;

    // Call the functions to check if the strings are one edit away
    bool isOneEdit_CharacterComparison = isOneEditAway_CharacterComparison(str1, str2);
    bool isOneEdit_FrequencyCount = isOneEditAway_FrequencyCount(str1, str2);
    bool isOneEdit_BitManipulation = isOneEditAway_BitManipulation(str1, str2);

    cout << "Output (Character Comparison): " << (isOneEdit_CharacterComparison ? "True" : "False") << endl;
    cout << "Output (Frequency Count): " << (isOneEdit_FrequencyCount ? "True" : "False") << endl;
    cout << "Output (Bit Manipulation): " << (isOneEdit_BitManipulation ? "True" : "False") << endl;

    return 0;
}

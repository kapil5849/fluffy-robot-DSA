#include <iostream>
#include <string>
using namespace std;
// Approach 1: Counting and Appending
string compressString_CountAndAppend(const string& str) {
    int length = str.length();
    if (length <= 1) {
        // If the string has length 0 or 1, no compression is possible
        return str;
    }
    string compressed;
    int count = 1;
    for (int i = 1; i < length; i++) {
        if (str[i] == str[i - 1]) {
            // If the current character is the same as the previous character, increment the count
            count++;
        } else {
            // If the current character is different from the previous character,
            // append the previous character and its count to the compressed string
            compressed += str[i - 1] + to_string(count);
            count = 1;
        }
    }
    // Append the last character and its count to the compressed string
    compressed += str[length - 1] + to_string(count);
    // Check if the compressed string is shorter than the original string
    if (compressed.length() >= length) {
        return str;
    }
    return compressed;
}
// Approach 2: Two-Pointers
string compressString_TwoPointers(const string& str) {
    int length = str.length();
    if (length <= 1) {
        // If the string has length 0 or 1, no compression is possible
        return str;
    }
    string compressed;
    int count = 1;
    for (int i = 0, j = 1; j <= length; j++) {
        if (j < length && str[j] == str[i]) {
            // If the current character is the same as the previous character, increment the count
            count++;
        } else {
            // If the current character is different from the previous character,
            // append the previous character and its count to the compressed string
            compressed += str[i] + to_string(count);
            i = j;
            count = 1;
        }
    }
    // Check if the compressed string is shorter than the original string
    if (compressed.length() >= length) {
        return str;
    }
    return compressed;
}
// Approach 3: In-Place Compression
void compressStringInPlace(string& str) {
    int length = str.length();
    if (length <= 1) {
        // If the string has length 0 or 1, no compression is possible
        return;
    }
    string compressed;
    int count = 1;
    char previousChar = str[0];
    for (int i = 1; i < length; i++) {
        if (str[i] == previousChar) {
            // If the current character is the same as the previous character, increment the count
            count++;
        } else {
            // If the current character is different from the previous character,
            // append the previous character and its count to the compressed string
            compressed += previousChar + to_string(count);
            count = 1;
            previousChar = str[i];
        }
    }
    // Append the last character and its count to the compressed string
    compressed += previousChar + to_string(count);
    // Check if the compressed string is shorter than the original string
    if (compressed.length() < length) {
        str = compressed;
    }
    return;
}
int main() {
    string str = "aabcccccaaa";
    cout << "Input: " << str << endl;
    // Approach 1: Counting and Appending
    string compressedStr_CountAndAppend = compressString_CountAndAppend(str);
    cout << "Output (Counting and Appending): " << compressedStr_CountAndAppend << endl;
    // Approach 2: Two-Pointers
    string compressedStr_TwoPointers = compressString_TwoPointers(str);
    cout << "Output (Two-Pointers): " << compressedStr_TwoPointers << endl;
    // Approach 3: In-Place Compression
    compressStringInPlace(str);
    cout << "Output (In-Place Compression): " << str << endl;
    return 0;
}
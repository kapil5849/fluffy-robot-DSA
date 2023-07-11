#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Approach 1: Using an Auxiliary String
string URLifyAuxiliary(string str, int length) {
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
    return aux;
}

// Approach 2: In-Place Modification
void URLifyInPlace(char str[], int length) {
    int spaceCount = 0;
    int index;
    // Count the number of spaces in the given string
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    // Calculate the new length of the string after replacing spaces with "%20"
    int newLength = length + (spaceCount * 2);
    // Adjust the index to the new end of the modified string
    index = newLength - 1;
    // Traverse the given string from the end and move characters to their new positions
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index--] = '0';
            str[index--] = '2';
            str[index--] = '%';
        } else {
            str[index--] = str[i];
        }
    }
    // Add null terminator at the end of the modified string
    str[newLength] = '\0';
}

int main() {
    string str = "Mr John Smith";
    int trueLength = 13;
    cout << "Input: " << str << endl;
    
    // Approach 1: Using an Auxiliary String
    string modifiedStrAuxiliary = URLifyAuxiliary(str, trueLength);
    cout << "Modified (Using Auxiliary String): " << modifiedStrAuxiliary << endl;

    // Approach 2: In-Place Modification
    char modifiedStrInPlace[str.length()];
    strcpy(modifiedStrInPlace, str.c_str());
    URLifyInPlace(modifiedStrInPlace, trueLength);
    cout << "Modified (In-Place Modification): " << modifiedStrInPlace << endl;

    return 0;
}

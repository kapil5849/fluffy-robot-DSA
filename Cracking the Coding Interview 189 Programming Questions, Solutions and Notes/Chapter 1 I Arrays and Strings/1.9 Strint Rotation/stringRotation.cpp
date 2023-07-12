#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Approach 1: Concatenation and Substring Check
bool isRotation_Concatenation(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    string concatenated = str1 + str1;

    // Check if str2 is a substring of concatenated
    return concatenated.find(str2) != string::npos;
}

// Approach 2: Check Circular Shifts
bool isRotation_CircularShifts(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    int n = str1.length();

    // Perform circular shifts and check if any match str2
    for (int i = 0; i < n; i++) {
        string shifted = str1.substr(n - i) + str1.substr(0, n - i);
        if (shifted == str2) {
            return true;
        }
    }

    return false;
}

// Approach 3: Compare Sorted Strings
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

int main() {
    string str1 = "waterbottle";
    string str2 = "erbottlewat";

    // Approach 1: Concatenation and Substring Check
    if (isRotation_Concatenation(str1, str2)) {
        cout << str2 << " is a rotation of " << str1 << " (Approach 1)" << endl;
    } else {
        cout << str2 << " is not a rotation of " << str1 << " (Approach 1)" << endl;
    }

    // Approach 2: Check Circular Shifts
    if (isRotation_CircularShifts(str1, str2)) {
        cout << str2 << " is a rotation of " << str1 << " (Approach 2)" << endl;
    } else {
        cout << str2 << " is not a rotation of " << str1 << " (Approach 2)" << endl;
    }

    // Approach 3: Compare Sorted Strings
    if (isRotation_SortedStrings(str1, str2)) {
        cout << str2 << " is a rotation of " << str1 << " (Approach 3)" << endl;
    } else {
        cout << str2 << " is not a rotation of " << str1 << " (Approach 3)" << endl;
    }

    return 0;
}

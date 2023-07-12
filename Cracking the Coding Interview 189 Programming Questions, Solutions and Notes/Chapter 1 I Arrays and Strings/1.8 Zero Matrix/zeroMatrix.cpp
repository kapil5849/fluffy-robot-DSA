#include <iostream>
#include <vector>

using namespace std;

// Approach 1: Extra Space
void setZeroes_ExtraSpace(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> tempMatrix = matrix; // Create a new matrix as extra space

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                // Set entire row to 0
                for (int k = 0; k < cols; k++) {
                    tempMatrix[i][k] = 0;
                }
                // Set entire column to 0
                for (int k = 0; k < rows; k++) {
                    tempMatrix[k][j] = 0;
                }
            }
        }
    }

    matrix = tempMatrix; // Replace original matrix with the modified matrix
}

// Approach 2: Constant Space
void setZeroes_ConstantSpace(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<bool> rowZeros(rows, false);
    vector<bool> colZeros(cols, false);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rowZeros[i] = true;
                colZeros[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowZeros[i] || colZeros[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Approach 3: Constant Space with Markers
void setZeroes_ConstantSpaceMarkers(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColZero) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Approach 1: Extra Space
    vector<vector<int>> matrix1 = matrix; // Create a copy of the original matrix
    setZeroes_ExtraSpace(matrix1);
    cout << "Matrix with Zeroes (Extra Space):" << endl;
    printMatrix(matrix1);

    // Approach 2: Constant Space
    vector<vector<int>> matrix2 = matrix; // Create a copy of the original matrix
    setZeroes_ConstantSpace(matrix2);
    cout << "Matrix with Zeroes (Constant Space):" << endl;
    printMatrix(matrix2);

    // Approach 3: Constant Space with Markers
    vector<vector<int>> matrix3 = matrix; // Create a copy of the original matrix
    setZeroes_ConstantSpaceMarkers(matrix3);
    cout << "Matrix with Zeroes (Constant Space with Markers):" << endl;
    printMatrix(matrix3);

    return 0;
}

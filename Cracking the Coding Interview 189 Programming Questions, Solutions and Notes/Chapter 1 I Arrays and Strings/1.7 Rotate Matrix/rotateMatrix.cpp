#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Approach 1: Transpose and Reverse
void rotateMatrix_TransposeReverse(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Approach 2: Layer by Layer Swapping
void rotateMatrix_LayerByLayer(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Iterate through each layer of the matrix
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;

        // Perform swaps to rotate the elements in the layer
        for (int i = first; i < last; i++) {
            int offset = i - first;

            // Save top element
            int top = matrix[first][i];

            // Move left element to top
            matrix[first][i] = matrix[last - offset][first];

            // Move bottom element to left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Move right element to bottom
            matrix[last][last - offset] = matrix[i][last];

            // Move top element to right
            matrix[i][last] = top;
        }
    }
}

// Approach 3: Using an Auxiliary Matrix
void rotateMatrix_Auxiliary(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Create an auxiliary matrix of the same size
    vector<vector<int>> auxMatrix(n, vector<int>(n, 0));

    // Copy elements from original matrix to auxiliary matrix in rotated positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auxMatrix[j][n - i - 1] = matrix[i][j];
        }
    }

    // Replace original matrix with the rotated auxiliary matrix
    matrix = auxMatrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Approach 1: Transpose and Reverse
    vector<vector<int>> matrix1 = matrix; // Create a copy of the original matrix
    rotateMatrix_TransposeReverse(matrix1);
    cout << "Rotated Matrix (Transpose and Reverse):" << endl;
    printMatrix(matrix1);

    // Approach 2: Layer by Layer Swapping
    vector<vector<int>> matrix2 = matrix; // Create a copy of the original matrix
    rotateMatrix_LayerByLayer(matrix2);
    cout << "Rotated Matrix (Layer by Layer Swapping):" << endl;
    printMatrix(matrix2);

    // Approach 3: Using an Auxiliary Matrix
    vector<vector<int>> matrix3 = matrix; // Create a copy of the original matrix
    rotateMatrix_Auxiliary(matrix3);
    cout << "Rotated Matrix (Using Auxiliary Matrix):" << endl;
    printMatrix(matrix3);

    return 0;
}

> Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
# **Notes**
## **Transpose and Reverse**
- Transpose the matrix by iterating through each element and swapping its value with the corresponding element across the main diagonal.
- Reverse each row of the transposed matrix.
- The matrix will be rotated by 90 degrees.
```cpp
void rotateMatrix_TransposeReverse(vector<vector<int>>& matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
```
## **Layer by Layer Swapping**
- Divide the matrix into layers, starting from the outermost layer and moving towards the inner layers.
- For each layer, perform a series of swaps to rotate the elements.
   - Swap the top element with the right element.
   - Swap the right element with the bottom element.
   - Swap the bottom element with the left element.
   - Swap the left element with the top element.
- Continue this process for each layer, moving towards the center of the matrix.
- The matrix will be rotated by 90 degrees.
```cpp
void rotateMatrix_LayerByLayer(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}
```
## **Using an Auxiliary Matrix**
- Create a new auxiliary matrix of the same size as the original matrix.
- Copy each element from the original matrix to the corresponding rotated position in the auxiliary matrix.
   - For each element at row i and column j in the original matrix, copy it to row j and column (N-i-1) in the auxiliary matrix, where N is the size of the matrix.
- Replace the original matrix with the rotated auxiliary matrix.
- The matrix will be rotated by 90 degrees.
```cpp
void rotateMatrix_Auxiliary(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> auxMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auxMatrix[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = auxMatrix;
}
```
## **Time and Space Complexity**
| Approach                   | Time Complexity                  | Space Complexity  |
|----------------------------|----------------------------------|-------------------|
| Transpose and Reverse      | O(N^2)                           | O(1)              |
| Layer by Layer Swapping    | O(N^2)                           | O(1)              |
| Using an Auxiliary Matrix  | O(N^2)                           | O(N^2)            |

### Note:
- N represents the size of the matrix (number of rows or columns).
- The time complexity for all approaches is quadratic, as they iterate through each element of the NxN matrix.
- The space complexity for the Transpose and Reverse and Layer by Layer Swapping approaches is constant, O(1), as they perform the rotation in-place without requiring additional space proportional to the input.
- The space complexity for the Using an Auxiliary Matrix approach is O(N^2), as it creates a new matrix of the same size as the input matrix to store the rotated elements.

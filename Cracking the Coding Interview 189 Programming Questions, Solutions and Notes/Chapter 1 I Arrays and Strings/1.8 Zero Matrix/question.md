# Zero Matrix
> Given an MxN matrix, if an element in the matrix is 0, its entire row and column should be set to 0. This problem requires modifying the matrix in place.
## **Approach 1: Extra Space**
- Create a new matrix of the same size as the original matrix.
- Iterate through the original matrix and copy the elements to the new matrix.
   - If an element is 0, set the corresponding row and column in the new matrix to 0.
- Replace the original matrix with the new matrix.
```cpp
void setZeroes_ExtraSpace(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> tempMatrix = matrix; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < cols; k++) {
                    tempMatrix[i][k] = 0;
                }
                for (int k = 0; k < rows; k++) {
                    tempMatrix[k][j] = 0;
                }
            }
        }
    }
    matrix = tempMatrix; 
}
```
## **Approach 2: Constant Space**

- Create two boolean arrays, `rowZeros` and `colZeros`, of size M and N respectively, initialized to false.
- Iterate through the matrix and for each element:
   - If the element is 0, set `rowZeros[i]` and `colZeros[j]` to true.
- Iterate through the matrix again and for each element:
   - If `rowZeros[i]` is true or `colZeros[j]` is true, set the element to 0.
```cpp
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
```
## Approach 3: Constant Space with Markers

- Create two boolean variables, `firstRowZero` and `firstColZero`, initially set to false.
- Iterate through the matrix and for each element:
   - If the element is 0, set `matrix[i][0]` to 0 (to mark that the entire row needs to be set to 0) and `matrix[0][j]` to 0 (to mark that the entire column needs to be set to 0).
   - Also, if (i, j) is in the first row or first column and is 0, set `firstRowZero` to true or `firstColZero` to true, respectively.
- Iterate through the matrix again and for each element:
   - If either `matrix[i][0]` or `matrix[0][j]` is 0, set `matrix[i][j]` to 0.
- If `firstRowZero` is true, set all elements in the first row to 0.
- If `firstColZero` is true, set all elements in the first column to 0.
```cpp
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
```
## **Time and Space Complexity**

| Approach                      | Time Complexity | Space Complexity |
|-------------------------------|-----------------|------------------|
| Extra Space                   | O(M*N)          | O(M*N)           |
| Constant Space                | O(M*N)          | O(M+N)           |
| Constant Space with Markers   | O(M*N)          | O(1)             |

In the table above, M represents the number of rows in the matrix, and N represents the number of columns in the matrix. The time complexity is given in terms of the number of elements in the matrix (M*N). The space complexity is indicated as the maximum amount of additional space used by the algorithm.

Note that the space complexities differ for the three approaches. The Extra Space approach requires additional space for a new matrix of the same size as the original matrix, resulting in O(M*N) space complexity. The Constant Space approach uses two boolean arrays to track the rows and columns that need to be set to 0, resulting in O(M+N) space complexity. The Constant Space with Markers approach modifies the matrix in place without using any additional space, resulting in O(1) space complexity.

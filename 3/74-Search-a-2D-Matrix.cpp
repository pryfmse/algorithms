#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>&, int);

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;

    matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}; 
    target = 13;
    cout << searchMatrix(matrix, target);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) { return false; }

    int n = matrix.size(), m = matrix[0].size(), l = 0, r = m * n - 1, middle = (r - l) / 2 + l;

    while (l <= r) {
        if (matrix[middle / m][middle % m] == target) {
            return true;
        }

        if (matrix[middle / m][middle % m] > target) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }

        middle = (r - l) / 2 + l;
    }

    return false;
}

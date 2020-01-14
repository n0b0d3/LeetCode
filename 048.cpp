#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = i; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < (matrix.size()+1) / 2; ++j) {
                swap(matrix[i][j], matrix[i][matrix.size()-j-1]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };
    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

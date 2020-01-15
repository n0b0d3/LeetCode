#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() <= 0 || matrix[0].size() <= 0) {
            return result;
        }
        int top = 0; int left = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int idx = 0; int jdx = 0;
        while(true) {
            for(int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            ++top;
            if(top > bottom) {
                break;
            }
            for(int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            --right;
            if(left > right) {
                break;
            }
            for(int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            --bottom;
            if(top > bottom) {
                break;
            }
            for(int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;
            if(left > right) {
                break;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

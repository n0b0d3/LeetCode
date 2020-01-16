#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = n - 1;
        int idx = 0;
        if(n <= 0) {
            return result;
        }
        while(true) {
            for(int i = left; i <= right; ++i) {
                ++idx;
                result[top][i] = idx;
            }
            ++top;
            if(top > bottom) {
                break;
            }
            for(int i = top; i <= bottom; ++i) {
                ++idx;
                result[i][right] = idx;
            }
            --right;
            if(left > right) {
                break;
            }
            for(int i = right; i >= left; --i) {
                ++idx;
                result[bottom][i] = idx;
            }
            --bottom;
            if(top > bottom) {
                break;
            }
            for(int i = bottom; i >= top; --i) {
                ++idx;
                result[i][left] = idx;
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
    Solution s;
    vector<vector<int>> result = s.generateMatrix(1);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(height.size() < 2) {
            return 0;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(min(height[i], height[j]) * (j - i) > ans) {
                    ans = min(height[i], height[j]) * (j - i);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height) << endl;
}

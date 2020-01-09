#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int tar = 0;
        if(nums.size() < 3) {
            return target;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    return target;
                } else if(sum > target) {
                    if(abs(sum - target) < ans) {
                        tar = sum;
                        ans = abs(sum - target);
                    }
                    --k;
                } else {
                    if(abs(sum - target) < ans) {
                        tar = sum;
                        ans = abs(sum - target);
                    }
                    ++j;
                }
            }
        }
        return tar;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    cout << s.threeSumClosest(nums, 1) << endl;
}

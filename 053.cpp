#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        int result = INT_MIN;
        int sum = 0;
        int idx = 0;
        while(idx < nums.size()) {
            if(sum + nums[idx] < 0) {
                sum = 0;
                if(nums[idx] > result) {
                    result = nums[idx];
                }
            } else {
                sum += nums[idx];
                if(sum > result) {
                    result = sum;
                }
            }
            ++idx;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2};
    cout << s.maxSubArray(nums) << endl;
}

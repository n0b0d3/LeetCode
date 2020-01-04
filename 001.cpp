#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int i = 0;
        int j = 1;
        if(nums.size() <= 1) {
            return ret;
        }
        if(nums.size() == 2 && nums[0] + nums[1] == target) {
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    vector<int> ret = s.twoSum(nums, 9);
    for(int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << ' ';
    }
    return 0;
}

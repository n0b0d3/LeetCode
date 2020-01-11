#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return 1;
        }
        int ans = 1;
        int cur = nums[0];
        int idx = 1;
        while(idx < nums.size()) {
            if(nums[idx] != cur) {
                cur = nums[idx];
                ans += 1;
                ++idx;
            } else {
                nums.erase(nums.begin() + idx);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(nums) << endl;
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

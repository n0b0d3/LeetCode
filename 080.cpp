#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2) {
            return nums.size();
        }
        int last = nums[0]; int cnt = 0; int idx = 0;
        while(idx < nums.size()) {
            if(nums[idx] == last) {
                cnt++;
                if(cnt > 2) {
                    nums.erase(nums.begin() + idx);
                    --idx;
                }
            } else {
                last = nums[idx];
                cnt = 1;
            }
            ++idx;
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1, 2, 3, 3};
    cout << s.removeDuplicates(nums) << endl;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }
        int idx = 0;
        while(idx < nums.size()) {
            if(nums[idx] == target) {
                return idx;
            }
            if(nums[idx] > target) {
                break;
            }
            ++idx;
        }
        return idx;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    cout << s.searchInsert(nums, 7) << endl;
}

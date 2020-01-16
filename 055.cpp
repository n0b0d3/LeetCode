#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > reach) {
                return false;
            }
            if(reach > nums.size() - 1) {
                return true;
            }
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.canJump(nums) << endl;
}

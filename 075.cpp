#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums.size() <= 0) {
            return;
        }
        int i = left;
        while(i <= right) {
            if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                ++i; ++left;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
            } else {
                ++i;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

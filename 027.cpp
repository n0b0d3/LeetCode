#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        while(idx < nums.size()) {
            if(nums[idx] == val) {
                nums.erase(nums.begin() + idx);
            } else {
                ++idx;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << s.removeElement(nums, 2) << endl;
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

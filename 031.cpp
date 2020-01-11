#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) {
            return;
        }
        int idx = nums.size() - 1;
        int jdx = nums.size() - 1;
        int last = nums[idx];
        while(idx >= 0) {
            if(nums[idx] >= last) {
                last = nums[idx];
                idx--;
            } else {
                break;
            }
        }
        while(jdx >= 0 && idx >= 0) {
            if(nums[jdx] <= nums[idx]) {
                --jdx;
            } else {
                swap(nums[idx], nums[jdx]);
                break;
            }
        }
        int mdx = idx + 1;
        int ndx = nums.size() - 1;
        while(mdx <= ndx) {
            if(nums[mdx] >= nums[ndx]) {
                swap(nums[mdx], nums[ndx]);
            }
            ++mdx;
            --ndx;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 1};
    s.nextPermutation(nums);
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

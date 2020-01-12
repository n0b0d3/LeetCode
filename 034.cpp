#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                int idx = left; int jdx = right;
                while(idx <= mid && nums[idx] != target) {
                    ++idx;
                }
                result.push_back(idx);
                while(jdx >= mid && nums[jdx] != target) {
                    --jdx;
                }
                result.push_back(jdx);
                break;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(result.size() == 0) {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> result = s.searchRange(nums, 6);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

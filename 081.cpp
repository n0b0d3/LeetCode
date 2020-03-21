#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return false;
        }
        int left = 0; int right = nums.size() -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                if(nums[mid] == nums[right]) {
                    right--;
                } else if(nums[mid] == nums[left]) {
                    left++;
                } else if(nums[mid] < nums[right]) {
                    right = mid - 1;
                } else if(nums[mid] > nums[left]) {
                    if(nums[left] == target) {
                        return true;
                    } else if(nums[left] > target) {
                        left = mid + 1;
                    } else if(nums[left] < target) {
                        right = mid - 1;
                    }
                }
            } else if(nums[mid] < target) {
                if(nums[mid] == nums[right]) {
                    right--;
                } else if(nums[mid] == nums[left]) {
                    left++;
                } else if(nums[mid] > nums[left]) {
                    left = mid + 1;
                } else if(nums[mid] < nums[right]) {
                    if(nums[right] == target) {
                        return true;
                    } else if(nums[right] > target) {
                        left = mid + 1;
                    } else if(nums[right] < target) {
                        right = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 1, 3, 1};
    cout << s.search(nums, 3) << endl;
}

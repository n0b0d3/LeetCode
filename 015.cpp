#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() - 2) {
            int j = i + 1;
            int k = nums.size() - 1;
            int t = nums[i];
            while(j < k) {
                vector<int> temp;
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    result.push_back(temp);
                    int t0 = nums[j];
                    int t1 = nums[k];
                    while(nums[j] == t0) {
                        ++j;
                        if(j >= k) {
                            break;
                        }
                    }
                    while(nums[k] == t1) {
                        --k;
                        if(j >= k) {
                            break;
                        }
                    }
                } else if (sum > 0) {
                    --k;
                } else {
                    ++j;
                }

            }
            while(nums[i] == t) {
                ++i;
                if(i >= nums.size() - 2) {
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> result = s.threeSum(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

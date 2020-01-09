#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() - 3) {
            int j = i + 1;
            int t0 = nums[i];
            while(j < nums.size() - 2) {
                int k = j + 1;
                int m = nums.size() - 1;
                int t1 = nums[j];
                while(k < m) {
                    vector<int> temp;
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if(sum == target) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[m]);
                        result.push_back(temp);
                        int t2 = nums[k];
                        int t3 = nums[m];
                        while(nums[k] == t2) {
                            ++k;
                            if(k >= m) {
                                break;
                            }
                        }
                        while(nums[m] == t3) {
                            --m;
                            if(k >= m) {
                                break;
                            }
                        }
                    } else if(sum > target) {
                        --m;
                    } else {
                        ++k;
                    }
                }
                while(nums[j] == t1) {
                    ++j;
                    if(j >= nums.size() - 2) {
                        break;
                    }
                }
            }
            while(nums[i] == t0) {
                ++i;
                if(i >= nums.size() - 3) {
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> result = s.fourSum(nums, 1);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

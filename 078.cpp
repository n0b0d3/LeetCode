#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ret;
        vector<vector<int>> result;
        vector<bool> isVisit(nums.size(), false);
        for(int i = 0; i <= nums.size(); ++i) {
            subset(result, ret, isVisit, nums, 0, 0, i);
        }
        return result;
    }
    void subset(vector<vector<int>> &result, vector<int> ret, vector<bool> &isVisit,
            vector<int> nums, int k, int idx, int target) {
        if(k == target) {
            result.push_back(ret);
            return;
        }
        for(int i = idx; i < isVisit.size(); ++i) {
            if(isVisit[i] == false) {
                isVisit[i] = true;
                ret.push_back(nums[i]);
                subset(result, ret, isVisit, nums, k + 1, i + 1, target);
                ret.pop_back();
                isVisit[i] = false;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0};
    vector<vector<int>> result = s.subsets(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

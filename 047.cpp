#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> isVisit(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(result, nums, cur, isVisit);
        return result;
    }
    void dfs(vector<vector<int>> &result, vector<int> &nums,
            vector<int> &cur, vector<bool> &isVisit) {
        if(cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(isVisit[i] == false) {
                if(i > 0 && nums[i] == nums[i-1] && isVisit[i-1]) {
                    continue;
                }
                isVisit[i] = true;
                cur.push_back(nums[i]);
                dfs(result, nums, cur, isVisit);
                cur.pop_back();
                isVisit[i] = false;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 0, 3};
    vector<vector<int>> result = s.permuteUnique(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

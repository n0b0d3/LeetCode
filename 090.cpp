#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<bool> isVisit(nums.size(), false);
        map<vector<int>, bool> checked;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); ++i) {
            subset(result, tmp, i, 0, isVisit, nums, checked);
        }
        return result;
    }
    void subset(vector<vector<int>> &result, vector<int> &tmp, int target, int idx,
            vector<bool> isVisit, vector<int> &nums, map<vector<int>, bool> &checked) {
        if(idx == target) {
            map<vector<int>, bool>::iterator it = checked.find(tmp);
            if(it == checked.end()) {
                result.push_back(tmp);
                checked[tmp] = true;
            }
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(!isVisit[i]) {
                tmp.push_back(nums[i]);
                isVisit[i] = true;
                subset(result, tmp, target, idx + 1, isVisit, nums, checked);
                tmp.pop_back();
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> nums = {4, 4, 4, 1, 4};
    vector<vector<int>> result = s.subsetsWithDup(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

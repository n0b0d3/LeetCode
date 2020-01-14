#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> isVisit(nums.size(), false);
        per(result, nums, cur, isVisit);
        return result;
    }
    void per(vector<vector<int>> &result, vector<int> &nums,
            vector<int> &cur, vector<bool> &isVisit) {
        if(cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(isVisit[i] == false) {
                cur.push_back(nums[i]);
                isVisit[i] = true;
                per(result, nums, cur, isVisit);
                cur.pop_back();
                isVisit[i] = false;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        candidate(result, cur, candidates, target, 0);
        return result;
    }
    void candidate(vector<vector<int>> &result, vector<int> &cur,
            vector<int> &candidates, int target, int pos) {
        if(target == 0) {
            result.push_back(cur);
            return;
        }
        for(int i = pos; i < candidates.size(); ++i) {
            if(candidates[i] > target) {
                return;
            }
            cur.push_back(candidates[i]);
            candidate(result, cur, candidates, target - candidates[i], i);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 6, 7};
    vector<vector<int>> result = s.combinationSum(nums, 7);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

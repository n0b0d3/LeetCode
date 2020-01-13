#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        set<vector<int>> capacity;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        candidate(result, cur, candidates, capacity, target, 0);
        return result;
    }
    void candidate(vector<vector<int>> &result, vector<int> &cur,
            vector<int> &candidates, set<vector<int>> &capacity, int target, int pos) {
        if(target == 0) {
            if(capacity.find(cur) != capacity.end()) {
                return;
            }
            capacity.insert(cur);
            result.push_back(cur);
            return;
        }
        for(int i = pos; i < candidates.size(); ++i) {
            if(candidates[i] > target) {
                return;
            }
            cur.push_back(candidates[i]);
            candidate(result, cur, candidates, capacity, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = s.combinationSum2(nums, 8);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

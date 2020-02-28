#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ret;
        vector<vector<int>> result;
        vector<bool> isVisit(n, false);
        if(n == 0 || k == 0) {
            return result;
        }
        merge(result, ret, isVisit, 0, 0, k);
        return result;
    }
    void merge(vector<vector<int>> &result, vector<int> ret, vector<bool> &isVisit,
            int k, int idx, int target) {
        if(k == target) {
            result.push_back(ret);
            return;
        }
        for(int i = idx; i < isVisit.size(); ++i) {
            if(isVisit[i] == false) {
                isVisit[i] = true;
                ret.push_back(i + 1);
                merge(result, ret, isVisit, k + 1, i + 1, target);
                ret.pop_back();
                isVisit[i] = false;
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> result = s.combine(4, 2);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

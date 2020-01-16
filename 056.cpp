#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    static bool cmp(vector<int> &x, vector<int> &y) {
        return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() <= 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(end >= intervals[i][0]) {
                if(end < intervals[i][1]) {
                    end = intervals[i][1];
                }
            } else {
                vector<int> ret;
                ret.push_back(start);
                ret.push_back(end);
                result.push_back(ret);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> ret;
        ret.push_back(start);
        ret.push_back(end);
        result.push_back(ret);
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {
        {1, 4},
        {4, 5},
    };
    vector<vector<int>> result = s.merge(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0;j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

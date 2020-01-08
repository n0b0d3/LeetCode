#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if(strs.size() == 0) {
            return ret;
        }
        if(strs.size() == 1) {
            return strs[0];
        }
        int ans = INT_MAX; string target = "";
        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i].size() < ans) {
                ans = strs[i].size();
                target = strs[i];
            }
        }
        for(int i = 0; i < target.size(); ++i) {
            for(int j = 0; j < strs.size(); ++j) {
                if(strs[j][i] != target[i]) {
                    return ret;
                }
            }
            ret += target[i];
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
}

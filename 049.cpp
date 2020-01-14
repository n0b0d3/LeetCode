#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> capacity;
        if(strs.size() <= 0) {
            return result;
        }
        for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(capacity.find(tmp) != capacity.end()) {
                capacity[tmp].push_back(strs[i]);
            } else {
                vector<string> cap;
                cap.push_back(strs[i]);
                capacity[tmp] = cap;
            }
        }
        for(auto c : capacity) {
            result.push_back(c.second);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = s.groupAnagrams(strs);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

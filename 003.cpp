#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        set<int> ret;
        int i = 0; int j = 0;
        while(i < s.size() && j < s.size()) {
            if(ret.find(s[j]) == ret.end()) {
                ret.insert(s[j++]);
                if(j - i > ans) {
                    ans = j - i;
                }
            } else {
                ret.erase(s[i++]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("aaa") << endl;
}

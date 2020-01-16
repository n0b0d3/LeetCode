#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int idx = s.size() - 1;
        if(s.size() <= 0) {
            return 0;
        }
        while(idx >= 0 && s[idx] == ' ') {
            --idx;
        }
        while(idx >= 0 && s[idx] != ' ') {
            --idx;
            ++cnt;
        }
        return cnt;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLastWord("a ") << endl;
}

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int start = 0;
        if(s.size() <= 1) {
            return s;
        }
        for(int i = 0; i < s.size(); ++i) {
            int j = i; int k = i;
            check(s, j, k, start, len);
            j = i - 1; k = i;
            check(s, j, k, start, len);
            j = i; k = i + 1;
            check(s, j, k, start, len);
        }
        return s.substr(start, len);
    }
    void check(string &s, int &j, int &k, int &start, int &len) {
        while(j >= 0 && k <= s.size()) {
            if(s[j] == s[k]) {
                if(k - j + 1 > len) {
                    len = k - j + 1;
                    start = j;
                }
                --j; ++k;
            } else {
                break;
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
}

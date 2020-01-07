#include <iostream>

using namespace std;

/*
 *第1行: 0, m, 2m, 3m...
 *第2行: 1，m-1, m+1, 2m-1, 2m+1, ...
 *第3行: 2，m-2, m+2, 2m-2, 2m+2, ...
 *...
 *第n-1行: n-2, m-(n-2), m+(n-2), 2m-(n-2), ...
 *第n行: n-1, m+n-1, 2m+n-1, ...
 */

class Solution {
public:
    string convert(string s, int numRows) {
        string ret = "";
        if(numRows < 2) {
            return s;
        }
        for(int i = 0; i < numRows; ++i) {
            for(int j = i; j < s.size(); j += 2 * (numRows - 1)) {
                ret += s[j];
                if(i > 0 && i < numRows - 1) {
                    if(2 * (numRows - 1 - i) + j < s.size()) {
                        ret += s[2 * (numRows - 1 - i) + j];
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
}

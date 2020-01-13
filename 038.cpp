#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if(n <= 0) {
            return "";
        }
        while(--n > 0) {
            int jdx = 0;
            string tmp = "";
            int last = result[0];
            int cnt = 0;
            while(jdx < result.size()) {
                if(result[jdx] == last) {
                    ++cnt;
                } else {
                    tmp += to_string(cnt);
                    tmp += last;
                    cnt = 1;
                    last = result[jdx];
                }
                ++jdx;
            }
            tmp += to_string(cnt);
            tmp += last;
            result = tmp;
        }
        return result;
    };
};

int main() {
    Solution s;
    cout << s.countAndSay(6) << endl;
}

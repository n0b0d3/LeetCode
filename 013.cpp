#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<string> k = {"M", "CM", "D", "CD", "C", "XC", "L",
                            "XL", "X", "IX", "V", "IV", "I"};
        vector<int> v = {1000, 900, 500, 400, 100, 90, 50,
                         40, 10, 9, 5, 4, 1};
        if(s.empty()) {
            return 0;
        }

        int n = 0;
        int ret = 0;
        while(n < s.size()) {
            for(int i = 0; i < k.size(); ++i) {
                if(s.substr(n, k[i].size()) == k[i]) {
                    n += k[i].size();
                    ret += v[i];
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
}

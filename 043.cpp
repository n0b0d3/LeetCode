#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret = "";
        vector<int> result(num1.size() + num2.size(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int c = 0;
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        for(int i = 0; i < num1.size(); ++i) {
            int j = 0;
            int s = 0;
            while(j < num2.size()) {
                s = result[i + j] + (num1[i] - '0') * (num2[j] - '0') + c;
                c = s / 10;
                s = s % 10;
                result[i + j] = s;
                ++j;
            }
            if(c > 0) {
                result[i + j] = c;
                c = 0;
            }
        }
        reverse(result.begin(), result.end());
        int k = 0;
        while(k < result.size() && result[k] == 0) {
            ++k;
        }
        while(k < result.size()) {
            ret += result[k] + '0';
            ++k;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.multiply("2", "3") << endl;
}

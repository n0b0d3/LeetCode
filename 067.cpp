#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1;
        int n = b.size() - 1;
        int c = 0;
        string result = "";
        while(m >= 0 && n >= 0) {
            int s = c + a[m] - '0' + b[n] - '0';
            c = s / 2;
            result += s % 2 + '0';
            --m;
            --n;
        }
        while(m >= 0) {
            int s = c + a[m] - '0';
            c = s / 2;
            result += s % 2 + '0';
            --m;
        }
        while(n >= 0) {
            int s = c + b[n] - '0';
            c = s / 2;
            result += s % 2 + '0';
            --n;
        }
        if(c > 0) {
            result += c + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("1010", "1011") << endl;
}

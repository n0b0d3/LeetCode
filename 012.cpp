#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        map<int, string> symbol = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        vector<int> number = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int n = number.size() - 1;
        while(num != 0 && n >= 0) {
            int circle = num / number[n];
            if(circle > 0) {
                for(int i = 0; i < circle; ++i) {
                    ret += symbol[number[n]];
                }
                num -= circle * number[n];
            }
            --n;

        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(1994) << endl;
}

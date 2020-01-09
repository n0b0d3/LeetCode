#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map<char, string> symbol = {
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
            {'0', ""}
        };
        if(digits.size() == 0) {
            return result;
        }
        result.push_back("");
        for(int i = 0; i < digits.size(); ++i) {
            vector<string> tmp;
            string c = symbol[digits[i]];
            for(int j = 0; j < c.size(); ++j) {
                for(int k = 0; k < result.size(); ++k) {
                    tmp.push_back(result[k] + c[j]);
                }
            }
            result = tmp;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.letterCombinations("");
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

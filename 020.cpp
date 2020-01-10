#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> result;
        map<char, char> Left = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };
        map<char, char> Right = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        for(int i = 0; i < s.size(); ++i) {
            if(Left.find(s[i]) != Left.end()) {
                result.push(s[i]);
            }
            if(Right.find(s[i]) != Right.end()) {
                if(result.empty()) {
                    return false;
                }
                if(Right[s[i]] != result.top()) {
                    return false;
                }
                result.pop();
            }
        }
        if(result.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isValid("{[]}") << endl;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", n, n);
        return result;
    }
    void generate(vector<string> &result, string s, int l, int r) {
        if(l == 0 && r == 0) {
            result.push_back(s);
            return;
        }
        if(l > 0) {
            generate(result, s + "(", l - 1, r);
        }
        if(l < r && r > 0) {
            generate(result, s + ")", l, r - 1);
        }
    }
};

int main() {
    Solution s;
    vector<string> result = s.generateParenthesis(3);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}

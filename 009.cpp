#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> result;
        if(x == 0) {
            return true;
        }
        if(x < 0) {
            return false;
        }
        while(x !=0) {
            result.push_back(x % 10);
            x = x / 10;
        }
        int i = 0; int j = result.size() - 1;
        while(i <= j) {
            if(result[i] != result[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(1221) << endl;
}

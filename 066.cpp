#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> result(digits.size() + 1, 0);
        for(int i = digits.size() - 1; i >= 0; --i) {
            int m = c + digits[i];
            result[i + 1] = m % 10;
            c = m / 10;
        }
        if(c > 0) {
            result[0] = c;
        } else {
            result.erase(result.begin(), result.begin() + 1);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0};
    vector<int> result = s.plusOne(nums);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

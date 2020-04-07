#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        if(n <= 0) {
            return result;
        }
        for(int i = 1; i <= n; ++i) {
            vector<int> tmp;
            for(int j = result.size() - 1; j >= 0; --j) {
                tmp.push_back(result[j] + pow(2, i - 1));
            }
            for(int k = 0; k < tmp.size(); ++k) {
                result.push_back(tmp[k]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.grayCode(3);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

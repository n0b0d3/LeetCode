#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
            for(int j = m + i - 1; j >= 0; --j) {
                if(nums1[j] > nums1[j + 1]) {
                    swap(nums1[j], nums1[j + 1]);
                }
            }
        }
    }
};

int main() {
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for(int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << ' ';
    }
    cout << endl;
}

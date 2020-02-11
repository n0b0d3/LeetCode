#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode * root = head;

        if(head == NULL || k == 0) {
            return root;
        }

        while(head->next != NULL) {
            head = head->next;
            ++len;
        }
        ++len;
        head->next = root;

        k = len - k % len;
        head = root;
        while(k > 1) {
            head = head->next;
            --k;
        }
        root = head->next;
        head->next = NULL;
        return root;
    };
};

int main() {
    vector<int> nums = {};
    Solution s;
    ListNode * root = new ListNode(-1);
    ListNode * head = root;
    for(int i = 0; i < nums.size(); ++i) {
        ListNode * tmp = new ListNode(nums[i]);
        head->next = tmp;
        head = head->next;
    }
    ListNode * ret = s.rotateRight(root->next, 4);
    while(ret != NULL) {
        cout << ret->val << ' ';
        ret = ret->next;
    }
    cout << endl;
}

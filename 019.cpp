#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * pre = new ListNode(-1);
        ListNode * cur = new ListNode(-1);
        pre->next = head;
        cur->next = head;
        ListNode * root = pre;
        while(n >= 0) {
            cur = cur->next;
            --n;
        }
        while(cur != NULL) {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode * delNode = pre->next;
        if(delNode != NULL) {
            pre->next = delNode->next;
        }
        return root->next;
    }
};

int main() {
    Solution s;
    ListNode * root = new ListNode(-1);
    ListNode * head = root;
    vector<int> nums = {1};
    for(int i = 0; i < nums.size(); ++i) {
        ListNode * tmp = new ListNode(nums[i]);
        tmp->next = head->next;
        head->next = tmp;
        head = head->next;
    }
    ListNode *result = s.removeNthFromEnd(root->next, 1);
    while(result != NULL) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
}

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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * left = new ListNode(-1);
        ListNode * right = new ListNode(-1);
        ListNode * p = left; ListNode * r = right;
        while(head != NULL) {
            ListNode * tmp = new ListNode(head->val);
            if(head->val < x) {
                tmp->next = p->next;
                p->next = tmp;
                p = p->next;
            } else {
                tmp->next = r->next;
                r->next = tmp;
                r = r->next;
            }
            head = head->next;
        }
        p->next = right->next;
        return left->next;
    }
};

int main() {
    vector<int> nums = {1, 4, 3, 2, 5, 2};
    Solution s;
    ListNode * root = new ListNode(-1);
    ListNode * head = root;
    for(int i = 0; i < nums.size(); ++i) {
        ListNode * tmp = new ListNode(nums[i]);
        tmp->next = head->next;
        head->next = tmp;
        head = head->next;
    }
    ListNode * ret = s.partition(root->next, 3);
    while(ret != NULL) {
        cout << ret->val << ' ';
        ret = ret->next;
    }
    cout << endl;
}

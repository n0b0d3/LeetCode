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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * ret = new ListNode(-1);
        ListNode * s = ret;
        ListNode *p = head; ListNode *r = head->next;
        while(r != NULL) {
            if(p->val == r->val) {
                r = r->next;
            } else {
                ListNode * tmp = new ListNode(p->val);
                tmp->next = s->next;
                s->next = tmp;
                s = s->next;
                p = r;
                r = r->next;
            }
        }
        if(p != NULL) {
            ListNode * tmp = new ListNode(p->val);
            tmp->next = s->next;
            s->next =tmp;
        }
        return ret->next;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2};
    ListNode * root = new ListNode(-1);
    ListNode * head = root;
    for(int i = 0; i < nums.size(); ++i) {
        ListNode * tmp = new ListNode(nums[i]);
        tmp->next = head->next;
        head->next = tmp;
        head = head -> next;
    }
    ListNode * ret = s.deleteDuplicates(root->next);
    while(ret != NULL) {
        cout << ret->val << ' ';
        ret = ret->next;
    }
    cout << endl;
}

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
        ListNode *ret = new ListNode(-1);
        ListNode *root = ret;
        ListNode *p = head;
        ListNode *r = head->next;
        bool isDup = false;
        while(r != NULL) {
            if(p->val == r->val) {
                r = r->next;
                isDup = true;
            } else {
                if(!isDup) {
                    ListNode * temp = new ListNode(p->val);
                    temp->next = root->next;
                    root->next = temp;
                    root = root->next;
                }
                p = r;
                r = r->next;
                isDup = false;
            }
        }
        if(!isDup) {
            ListNode * temp = new ListNode(p->val);
            temp->next = root->next;
            root->next = temp;
            root = root->next;
        }
        return ret->next;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2};
    Solution s;
    ListNode * root = new ListNode(-1);
    ListNode * head = root;
    for(int i = 0; i < nums.size(); ++i) {
        ListNode * tmp = new ListNode(nums[i]);
        tmp->next = head->next;
        head->next = tmp;
        head = head->next;
    }
    ListNode * ret = s.deleteDuplicates(root->next);
    while(ret != NULL) {
        cout << ret->val << ' ';
        ret = ret->next;
    }
    cout << endl;
}

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(-1);
        ListNode * head = result;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                ListNode * tmp = new ListNode(l1->val);
                tmp->next = head->next;
                head->next = tmp;
                head = head->next;
                l1 = l1->next;
            } else {
                ListNode * tmp = new ListNode(l2->val);
                tmp->next = head->next;
                head->next = tmp;
                head = head->next;
                l2 = l2->next;
            }
        }
        while(l1 != NULL) {
            ListNode * tmp = new ListNode(l1->val);
            tmp->next = head->next;
            head->next = tmp;
            head = head->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            ListNode * tmp = new ListNode(l2->val);
            tmp->next = head->next;
            head->next = tmp;
            head = head->next;
            l2 = l2->next;
        }
        return result->next;
    }
};

int main() {
    Solution s;
    ListNode * l1 = new ListNode(-1);
    ListNode * l2 = new ListNode(-2);
    ListNode * r1 = l1;
    ListNode * r2 = l2;
    vector<int> n1 = {1, 2, 4};
    vector<int> n2 = {1, 3, 4};
    for(int i = 0; i < n1.size(); ++i) {
        ListNode * tmp = new ListNode(n1[i]);
        tmp->next = l1->next;
        l1->next = tmp;
        l1 = l1->next;
    }
    for(int i = 0; i < n2.size(); ++i) {
        ListNode * tmp = new ListNode(n2[i]);
        tmp->next = l2->next;
        l2->next = tmp;
        l2 = l2->next;
    }
    ListNode * result = s.mergeTwoLists(r1->next, r2->next);
    while(result != NULL) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
}

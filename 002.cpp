/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1);
        ListNode *pre = ret;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int m = l1->val + l2->val + carry;
            int n = m % 10;
            carry = (m - n) / 10;
            ListNode *temp = new ListNode(n);
            temp->next = pre->next;
            pre->next = temp;
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            int m = l1->val + carry;
            int n = m % 10;
            carry = (m-n) / 10;
            ListNode *temp = new ListNode(n);
            temp->next = pre->next;
            pre->next = temp;
            pre = pre->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int m = l2->val + carry;
            int n = m % 10;
            carry = (m-n) / 10;
            ListNode *temp = new ListNode(n);
            temp->next = pre->next;
            pre->next = temp;
            pre = pre->next;
            l2 = l2->next;
        }
        if(carry != 0) {
            ListNode *temp = new ListNode(carry);
            temp->next = pre->next;
            pre->next = temp;
            pre = pre->next;
        }
        return ret->next;
    }
};

int main() {
    vector<int> a = {2, 4, 3};
    vector<int> b = {5, 6, 4};
    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-1);
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    for(int i = 0; i < a.size(); ++i) {
        ListNode *temp = new ListNode(a[i]);
        temp->next = p1->next;
        p1->next = temp;
        p1 = p1->next;
    }
    for(int i = 0; i < b.size(); ++i) {
        ListNode *temp = new ListNode(b[i]);
        temp->next = p2->next;
        p2->next = temp;
        p2 = p2->next;
    }
    Solution s;
    ListNode *ret = s.addTwoNumbers(l1->next, l2->next);
    while(ret != NULL) {
        cout << ret->val << ' ';
        ret = ret->next;
    }
    cout << endl;
    return 0;
}

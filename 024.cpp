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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * root = new ListNode(-1);
        ListNode * ori_root = root;
        root->next = head;
        ListNode * pre = head;
        ListNode * cur = head->next;

        while(pre != NULL && cur != NULL) {
            pre->next = cur->next;
            cur->next = pre;
            root->next = cur;
            root = pre;
            pre = pre->next;
            if(pre == NULL) {
                break;
            }
            cur = pre->next;
        }
        return ori_root->next;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2};
    ListNode * head = new ListNode(-1);
    ListNode * root = head;
    for(int i = 0; i < nums.size(); ++i) {
        ListNode * tmp = new ListNode(nums[i]);
        tmp->next = head->next;
        head->next = tmp;
        head = head->next;
    }
    ListNode * result = s.swapPairs(root->next);
    while(result != NULL) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2;
        while (l1 != NULL) {
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            num2.push_back(l2->val);
            l2 = l2->next;
        }
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int carry = 0;
        ListNode* res = NULL;
        while (index1 >=0 && index2 >= 0) {
            int tmp = num1[index1] + num2[index2] + carry;
            ListNode* p = new ListNode(0);
            if (tmp > 9) {
                p->val = tmp - 10;
                carry = 1;
            } else {
                p->val = tmp;
                carry = 0;
            }
            p->next = res;
            res = p;
            index1--;
            index2--;
        }
        while (index1 >= 0) {
            int tmp = num1[index1] + carry;
            ListNode* p = new ListNode(0);
            if (tmp > 9) {
                p->val = tmp - 10;
                carry = 1;
            } else {
                p->val = tmp;
                carry = 0;
            }
            p->next = res;
            res = p;
            index1--;
        }
        while (index2 >= 0) {
            int tmp = num2[index2] + carry;
            ListNode* p = new ListNode(0);
            if (tmp > 9) {
                p->val = tmp - 10;
                carry = 1;
            } else {
                p->val = tmp;
                carry = 0;
            }
            p->next = res;
            res = p;
            index2--;
        }
        if (carry == 1) {
            ListNode* p = new ListNode(1);
            p->next = res;
            res = p;
            cout << p->val << endl;
        }
        return res;
    }
};
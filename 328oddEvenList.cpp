class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL|| head->next == NULL || head->next->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        while (even != NULL && even->next != NULL) {
            ListNode* p = even->next;
            even->next = p->next;
            p->next = odd->next;
            odd->next = p;
            odd = odd->next;
            even = even->next;
        }
        return head;
    }
};
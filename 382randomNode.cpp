class Solution {
private:
    ListNode* p;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = 0;
        int cnt = 1;
        ListNode* node = p;
        while(node) {
            int n = rand() % cnt;
            if (n == 0) res = node->val;
            node = node->next;
            cnt++;
        }
        return res;
    }
};

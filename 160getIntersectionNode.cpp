#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        if (headA == headB) return headA;
        else if (headA->next == NULL && headB->next == NULL) return NULL;
        if (headA->next == NULL) {
            ListNode* nodeB = headB;
            while (nodeB != NULL) {
                if (nodeB == headA) return headA;
                nodeB = nodeB->next;
            }
            return NULL;
        }
        if (headB->next == NULL) {
            ListNode* nodeA = headA;
            while (nodeA != NULL) {
                if (nodeA == headB) return headB;
                nodeA = nodeA->next;
            }
            return NULL;
        }
        int lenA = 1, lenB = 1;
        ListNode* node = headA;
        while (node->next != NULL) {
            lenA++;
            node = node->next;
        }
        node = headB;
        while(node->next != NULL) {
            lenB++;
            node = node->next;
        }
        int diff = lenB - lenA;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        if (diff > 0) {
            for (int i = 0; i < diff; i++) nodeB = nodeB->next;
        }
        else {
            for (int i = 0; i < (0 - diff); i++) nodeA = nodeA->next;
        }
        if (nodeA == nodeB) return nodeA;
        while (nodeA->next != NULL && nodeB->next != NULL) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            if (nodeA == nodeB) return nodeA;
        }
        return NULL;
    }
};
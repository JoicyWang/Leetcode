#include <stdint.h>
#include <iostream>
using namespace std;

 // two points, reverse the list from mid
class Solution {
public:
    bool isPalindrome(ListNode* head) {
         if (head == NULL) return true;
         if (head->next == NULL) return true;
         ListNode* pl = head, *pr = head->next, *pf = head->next, *pt;
         head->next = NULL;
         while (pf->next != NULL && pf->next->next != NULL) {
             pf = pf->next->next;
             pt = pr->next;
             pr->next = pl;
             pl = pr;
             pr = pt;
         }
         if (pf->next != NULL) pr = pr->next;
         while (pr != NULL) {
             if (pl->val != pr->val) return false;
             else {
                 pl = pl->next;
                 pr = pr->next;
             }
         }
         return true;
    }
};
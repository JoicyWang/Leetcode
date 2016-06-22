#include <stdint.h>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* node = head;
		while ((node != NULL) && (node->next != NULL)) {
			if (node->next->val == node->val){
				ListNode* temp = node->next;
				node->next = temp->next;
				delete temp;
			}
			else
				node = node->next;
		}
		return head;
	}
};
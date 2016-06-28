#include <stdint.h>
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
	ListNode* reverseList(ListNode* head) {
		if ((head == NULL) || (head->next == NULL))
			return head;
		ListNode* p = head;
		ListNode* q = p->next;
		ListNode* t = head;
		while (q != NULL) {
			t = head;
			head = q;
			q = q->next;
			head->next = t;
			p->next = q;
		}
		return head;
	}
};
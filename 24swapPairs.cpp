#include <stdint.h>
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if ((head == NULL) || (head->next == NULL))
			return head;
		ListNode* p = head;
		ListNode* q = head->next;
		ListNode* t;
		head = head->next;
		while ((q != NULL) && (q->next != NULL) && (q->next->next != NULL)) {
			p->next = q->next;
			q->next = p;
			q = p->next;
			p->next = q->next;
			p = q;
			q = p->next;
		}
		p->next = q->next;
		q->next = p;
		return head;
	}
};
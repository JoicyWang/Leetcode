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
	bool hasCycle(ListNode *head) {
		if ((head == NULL) || (head->next == NULL))
			return false;
		ListNode* p = head;
		ListNode* q = head->next;
		while ((q != NULL) && (q->next != NULL)) {
			p = p->next;
			q = q->next->next;
			if (p == q)
				return true;
		}
		return false;
	}
};
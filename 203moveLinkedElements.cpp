#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		ListNode *p = newHead;
		while (p != NULL)
		{
			if (p->next == NULL)
				p = p->next;
			else if (p->next->val == val)
			{
				ListNode *q = p->next;
				p->next = q->next;
				delete q;
			}
			else
				p = p->next;
		}
		return newHead->next;
	}
};

void test(vector<int> nums, int val)
{
	ListNode *head = new ListNode(nums[0]);
	ListNode *p = head;
	for (int i = 1; i < nums.size(); i++)
	{

		ListNode *n = new ListNode(nums[i]);
		p->next = n;
		p = p->next;
	}
	Solution test;
	p = test.removeElements(head, val);
	if (p == NULL)
	{
		cout << "There is a empty list" << endl;
		return;
	}
	while (p->next != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << p->val << endl;
}
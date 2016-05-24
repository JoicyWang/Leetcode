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
private:
	int count = 0;
	void nextNode(ListNode* node, int n)
	{
		if (node != NULL)
		{
			nextNode(node->next, n);
		}
		count++;
		if (count == n + 2)
			deleteNextNode(node);
	}
	void deleteNextNode(ListNode* node)
	{
		ListNode *q = node->next;
		node->next = q->next;
		delete q;
	}
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		nextNode(newHead, n);
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
	p = test.removeNthFromEnd(head, val);
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
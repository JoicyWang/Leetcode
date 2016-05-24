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
	void deleteNode(ListNode* node)
	{
		ListNode *q = node->next;
		node->val = q->val;
		node->next = q->next;
		delete q;
	}
};

void test(vector<int> nums, int val)
{
	ListNode *head = new ListNode(nums[0]);
	ListNode *node = head;
	ListNode *p = head;
	for (int i = 1; i < nums.size(); i++)
	{

		ListNode *n = new ListNode(nums[i]);
		p->next = n;
		p = p->next;
		if (i == val - 1)
			node = p;
	}
	cout << node->val << endl;
	Solution test;
	test.deleteNode(node);
	p = head;
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
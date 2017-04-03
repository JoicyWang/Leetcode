/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        queue<int> level;
        if (root == NULL)
            return res;
        que.push(root);
        level.push(0);
        res.push_back(root->val);
        while (!que.empty()) {
            TreeNode* p = que.front();
            que.pop();
            int l = level.front();
            level.pop();
            if (l >= res.size())
                res.push_back(p->val);
            if (p->left) {
                que.push(p->left);
                level.push(l + 1);
            }
            if (p->right) {
                que.push(p->right);
                level.push(l + 1);
            }
            if (p->val > res[l])
                res[l] = p->val;
        }
        return res;
    }
};
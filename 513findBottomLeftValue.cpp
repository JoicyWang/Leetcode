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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> level;
        q.push(root);
        level.push(0);
        int m = 0;
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            int l = level.front();
            level.pop();
            if (p->left) {
                q.push(p->left);
                level.push(l + 1);
            }
            if (p->right) {
                q.push(p->right);
                level.push(l + 1);
            }
            if (l > m) {
                m = l;
                root = p;
            }
        }
        return root->val;
    }
};
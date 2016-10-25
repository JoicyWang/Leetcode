class Solution {
public:
    TreeNode* array2bst(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int i = start + (end - start) / 2;
        TreeNode* n = new TreeNode(nums[i]);
        n->left = array2bst(nums, start, i - 1);
        n->right = array2bst(nums, i + 1, end);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return array2bst(nums, 0, nums.size() - 1);
    }
};
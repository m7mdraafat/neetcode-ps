/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* node, int &maxSum) {
        if (!node)
            return 0;
        int l = pathSum(node->left, maxSum);
        if (l < 0) l = 0;
        int r = pathSum(node->right, maxSum);
        if (r < 0) r = 0;
        maxSum = max(maxSum, (node->val + l + r));
        return node->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);

        return maxSum;
    }
};
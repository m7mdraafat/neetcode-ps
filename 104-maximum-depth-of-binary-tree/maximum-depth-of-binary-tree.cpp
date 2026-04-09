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
    int depth(TreeNode * node) {
        if (!node)
            return 0;
        
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        return 1 + max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode* root) {
        int answer = depth(root);

        return answer;
    }
};
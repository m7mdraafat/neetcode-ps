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
    int totalSum = 0;
public:
    void pathSum(TreeNode* node, int path = 0)
    {
        if (!node) {
            return;
        }

        path = path * 10 + node->val;

        if (!node->left && !node->right) {
            totalSum += path;
        }

        pathSum(node->left, path);
        pathSum(node->right, path);
    }

    int sumNumbers(TreeNode* root) {
        pathSum(root);
        return totalSum;
    }
};
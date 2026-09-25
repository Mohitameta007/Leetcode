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

    int height(TreeNode* root)
    {
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    bool balanced(TreeNode* root)
    {
        if(!root) return true;

        int left = height(root->left);
        int right = height(root->right);

        if(abs(left-right) > 1) return false;

        return balanced(root->left)&&balanced(root->right);

    }

    bool isBalanced(TreeNode* root) {
        return balanced(root);
    }
};
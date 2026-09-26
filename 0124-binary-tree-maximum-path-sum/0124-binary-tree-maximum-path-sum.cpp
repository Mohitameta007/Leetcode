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

    int sum(TreeNode* root , int& ans)
    {
        if(!root) return 0;

        int leftsum = max(0 , sum(root->left , ans));
        int rightsum = max(0 , sum(root->right , ans));

        ans = max(ans , root->val + leftsum+rightsum);

        return root->val+max(leftsum , rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        sum(root , ans);

        return ans;
    }
};
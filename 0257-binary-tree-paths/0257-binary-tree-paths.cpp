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

    void path(TreeNode* root , vector<string>& ans , string s)
    {
        if(!root) return;
        s += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(s);
            return;
        }
        if(root->left != nullptr || root->right != nullptr) s += "->";

        if(root->left) path(root->left , ans , s);
        if(root->right) path(root->right , ans , s);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        path(root , ans , s);

        return ans;
    }
};
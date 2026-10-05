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

    TreeNode* build(vector<int>& preorder , int isstart , int isend , int& preindx , unordered_map<int , int>&mpp)
    {
        if(isstart > isend) return nullptr;

        int rootval = preorder[preindx];
        preindx++;
        TreeNode* root = new TreeNode(rootval);
        auto it = mpp.find(rootval);

        root->left = build(preorder , isstart , it->second-1 , preindx , mpp);
        root->right = build(preorder , it->second+1 , isend , preindx , mpp);

        return root;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int isstart = 0;
        int isend = inorder.size()-1;
        int preindx = 0;
        unordered_map<int , int> mpp;

        for(int i = 0 ; i < inorder.size() ; i++)
        {
            mpp[inorder[i]] = i;
        }

        return build(preorder , isstart , isend , preindx , mpp);
    }
};
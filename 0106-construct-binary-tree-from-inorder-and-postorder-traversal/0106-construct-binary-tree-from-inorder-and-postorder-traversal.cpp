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

    TreeNode* build(vector<int>& postorder , int isstart , int isend , int& postindx , unordered_map<int , int>& mpp)
    {
        if(isstart > isend) return nullptr;

        int rootval = postorder[postindx];
        postindx--;
        TreeNode* root = new TreeNode(rootval);
        auto it = mpp.find(rootval);

        root->right = build(postorder , it->second+1 , isend , postindx , mpp);
        root->left = build(postorder , isstart , it->second-1 , postindx , mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int isstart = 0;
        int isend = inorder.size()-1;
        int postindx = postorder.size()-1;
        unordered_map<int , int> mpp;

        for(int i = 0 ; i < inorder.size() ; i++)
        {
            mpp[inorder[i]] = i;
        }

        return build(postorder , isstart , isend , postindx , mpp);
    }
};
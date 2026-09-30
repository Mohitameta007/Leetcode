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

    bool ancestorp(TreeNode* root , TreeNode* p , vector<TreeNode*>& pathp)
    {
        if(!root) return false;

        pathp.push_back(root);
        if(root == p) return true;

        if(ancestorp(root->left , p , pathp)) return true;
        if(ancestorp(root->right , p , pathp)) return true;

        pathp.pop_back();
        return false;
    }

    bool ancestorq(TreeNode* root , TreeNode* q , vector<TreeNode*>& pathq)
    {
        if(!root) return false;

        pathq.push_back(root);
        if(root == q) return true;

        if(ancestorq(root->left , q , pathq)) return true;
        if(ancestorq(root->right , q , pathq)) return true;

        pathq.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        ancestorp(root , p , pathp);
        ancestorq(root , q , pathq);

        int i = 0;
        while(i < pathp.size() && i < pathq.size() && pathp[i] == pathq[i])
        {
            i++;
        }

        return pathp[i-1];
    }
};
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

    vector<int> rightside(TreeNode* root)
    {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);

        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();

            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                if(node->right)
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                } 
                if(node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                q.pop();            
            }
            if(!temp.empty()) ans.push_back(temp[0]);
        }
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        return rightside(root);
    }
};
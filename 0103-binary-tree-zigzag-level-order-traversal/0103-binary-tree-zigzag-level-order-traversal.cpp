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

    vector<vector<int>> zigzag(TreeNode* root , vector<vector<int>>& ans)
    {
        if(!root) return ans;
        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();

            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                temp.push_back(node->val);
                q.pop();
            }

            if(flag == true)
            {
                ans.push_back(temp);
                flag = false;
            } 
            else{
                reverse(temp.begin() , temp.end());
                ans.push_back(temp);
                flag = true;
            }
        }

        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        zigzag(root , ans);
        return ans;
    }
};
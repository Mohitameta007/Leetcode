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

    vector<vector<int>> vertical(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int , map<int , vector<int>>> mpp;
        queue<tuple<int , int , TreeNode*>> q;
        q.push({0 , 0 , root});
        mpp[0][0].push_back(root->val);

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0 ; i < size ; i++)
            {
                auto [col, level, node] = q.front();
                q.pop();

                if(node->left)
                {
                    q.push({col-1 , level+1 , node->left});
                    mpp[col-1][level].push_back(node->left->val);
                }

                if(node->right)
                {
                    q.push({col+1 , level+1 , node->right});
                    mpp[col+1][level].push_back(node->right->val);
                }
            }
        }

        for(auto col : mpp)
        {
            vector<int> temp;
            for(auto level : col.second)
            {
                sort(level.second.begin(), level.second.end());
                for(auto value : level.second)
                {
                    temp.push_back(value);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return vertical(root);
    }
};
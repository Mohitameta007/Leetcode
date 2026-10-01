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

    int width(TreeNode* root)
    {
        long long ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});

        while(!q.empty())
        {
            long long size = q.size();
            long long firstindx = q.front().second;
            long long lastindx = 0;
            for(long long  i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front().first;
                long long indx = q.front().second - firstindx;
                if(node->left) q.push({node->left , 2*indx+1});
                if(node->right) q.push({node->right , 2*indx+2});

                if(i == size-1)
                {
                    lastindx = indx;
                }

                q.pop();
            }

            ans = max(ans , lastindx + 1);
        }

        return ans;
    }

    int widthOfBinaryTree(TreeNode* root) {
        return width(root);
    }
};
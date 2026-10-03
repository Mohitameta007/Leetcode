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

    TreeNode* search(TreeNode* root, int target)
    {
        TreeNode* start = nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->val == target) return node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return nullptr;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root , val);
    }
};
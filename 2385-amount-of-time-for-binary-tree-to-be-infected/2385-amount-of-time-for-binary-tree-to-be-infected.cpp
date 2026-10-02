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

    int time(TreeNode* root , int start)
    {
        int time = 0;
        unordered_map<TreeNode* , TreeNode*> mpp;
        unordered_set<TreeNode*> nonvis;
        queue<TreeNode*> q;
        TreeNode* startnode = nullptr;
        q.push(root);
        mpp[root] = nullptr;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                nonvis.insert(node);
                if(node->val == start) startnode = node;
                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                    mpp[node->left] = node;
                } 
                if(node->right) 
                {
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }
        }

        q.push(startnode);
        nonvis.erase(startnode);
        while(!q.empty())
        {
            if(nonvis.empty()) return time;
            int size = q.size();
            time++;
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                {
                    nonvis.erase(node->left);
                    q.push(node->left);
                }

                if(node->right)
                {
                    nonvis.erase(node->right);
                    q.push(node->right);
                }

                auto it = mpp.find(node);
                if(it != mpp.end() && it->second != nullptr)
                {
                    nonvis.erase(it->second);
                    q.push(it->second);
                }
            }
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        return time(root , start);
    }
};
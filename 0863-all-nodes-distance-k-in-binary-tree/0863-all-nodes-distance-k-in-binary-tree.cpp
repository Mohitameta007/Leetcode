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

    vector<int> dis(TreeNode* root , TreeNode* target , int k)
    {
        vector<int> ans;
        unordered_map<TreeNode* , TreeNode*> mpp;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(target);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* parent = q.front();
                if(parent->left)
                {
                    q.push(parent->left);
                    mpp[parent->left] = parent;
                } 
                if(parent->right)
                {
                    q.push(parent->right);
                    mpp[parent->right] = parent;
                }
                q.pop();
            }
        }

        q.push(target);
        while(!q.empty())
        {
            if(k == 0) break;
            k--;
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                if(node->left && visited.find(node->left) == visited.end())
                {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end())
                {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                auto it = mpp.find(node);
                if(it != mpp.end() && it->second != nullptr && visited.find(it->second) == visited.end()) 
                {
                    visited.insert(it->second);
                    q.push(it->second);
                }

                q.pop();
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        return dis(root , target , k);
    }
};
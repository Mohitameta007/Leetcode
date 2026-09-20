class Solution {
public:

    void perm(vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans , vector<bool>& used)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(used[i] != true)
            {
                temp.push_back(nums[i]);
                used[i] = true;
                perm(nums , temp , ans , used);
                used[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        perm(nums , temp , ans , used);

        return ans;
    }
};
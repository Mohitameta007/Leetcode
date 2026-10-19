class Solution {
public:

    vector<int> solve(vector<int>& nums , int target , vector<int>& ans)
    {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == target) ans.push_back(i);
        }

        return ans;
        }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        return solve(nums , target , ans);
    }
};
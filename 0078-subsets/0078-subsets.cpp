class Solution {
public:
    void sub(vector<int> nums , int indx , vector<vector<int>>& ans , vector<int>& subset)
    {
        if(indx >= nums.size())
        {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[indx]);
        sub(nums , indx+1 , ans , subset);

        subset.pop_back();
        sub(nums , indx+1 , ans , subset);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sub(nums , 0 , ans , subset);
        return ans;
    }
};
class Solution {
public:

    void subset(vector<int>& nums , int indx , vector<int>& temp , vector<vector<int>>& ans)
    {
        ans.push_back(temp);
        for(int i = indx ; i < nums.size() ; i++)
        {
            if(i > indx && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            subset(nums , i+1 , temp , ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int indx = 0;
        sort(nums.begin() , nums.end());
        subset(nums , indx , temp , ans);
        return ans;
    }
};
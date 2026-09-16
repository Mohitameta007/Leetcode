class Solution {
public:

    void combination(vector<int>& nums , int indx , int target , vector<int>& temp , vector<vector<int>>& ans)
    {
        if(indx == nums.size())
        {
            if(target == 0) ans.push_back(temp);
            return;
        }

        if(target >= nums[indx])
        {
            temp.push_back(nums[indx]);
            combination(nums , indx , target-nums[indx] , temp , ans);
            temp.pop_back();
            combination(nums , indx+1 , target , temp , ans);
        }
        else {
            combination(nums , indx+1 , target , temp , ans);
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int indx = 0;
        combination(candidates , indx , target , temp , ans);

        return ans;
    }
};
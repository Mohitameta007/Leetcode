class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] > maxi) maxi = nums[i];
            if(nums[i] < mini) mini = nums[i];
        }
        vector<bool> ans(maxi-mini+1 , false);
        vector<int> result;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans[nums[i] - mini] = true;
        }

        for(int i = 0 ; i < ans.size() ; i++)
        {
            if(ans[i] == false) result.push_back(i+mini);
        }

        return result;
    }
};
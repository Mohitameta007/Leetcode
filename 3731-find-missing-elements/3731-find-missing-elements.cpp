class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] > maxi) maxi = nums[i];
            if(nums[i] < mini) mini = nums[i];
        }
        int j = 0;
        for(int i = mini ; i < maxi ; i++)
        {
            if(i == nums[j]) j++;
            else ans.push_back(i);
        }

        return ans;
    }
};
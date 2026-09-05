class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxarr(nums.size() , 0);
        vector<int> minarr(nums.size() , 0);
        int maxi = 0;
        int mini = INT_MAX;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            maxi = max(maxi , nums[i]);
            maxarr[i] = maxi;
        }
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            mini = min(mini , nums[i]);
            minarr[i] = mini;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            int score = maxarr[i] - minarr[i];
            if(score <= k) return i;
        }

        return -1;
    }
};
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int maxi = 0;
            int mini = INT_MAX;
            for(int j = 0 ; j <= i ; j++)
            {
                maxi = max(maxi , nums[j]);
            }
            for(int k = i ; k < nums.size() ; k++)
            {
                mini = min(mini , nums[k]);
            }
            int score = maxi-mini;
            if(score <= k) return i;
        }

        return -1;
    }
};
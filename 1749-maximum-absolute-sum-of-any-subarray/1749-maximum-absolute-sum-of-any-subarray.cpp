class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax = 0;
        int currmin = 0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            currmax = max(nums[i] , currmax + nums[i]);
            currmin = min(nums[i] , currmin + nums[i]);
            maxsum = max(maxsum , currmax);
            minsum = min(minsum , currmin);
        }

        return max(maxsum , abs(minsum));
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int maxi = INT_MIN;
        while(end < nums.size())
        {
            sum += nums[end];
            maxi = max(maxi , sum);

            if(sum < 0)
            {
                start = end+1;
                end = start;
                sum = 0;
            }
            else{
                end++;
            }
        }

        return maxi;
    }
};
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int ans = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            low = max(low , nums[i]);
            high += nums[i];
        }
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int sum = 0;
            int subarr = 1;
            for(int i = 0 ; i < nums.size() ; i++)
            {
                sum += nums[i];
                if(i != nums.size()-1 && sum+nums[i+1] > mid)
                {
                    subarr++;
                    sum = 0;
                }
            }
            if(subarr > k) 
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
                ans = mid;
            } 
        }

        return ans;
    }
};
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            high = max(high , nums[i]);
        }

        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int count = 0;
            for(int i = 0 ; i < nums.size() ; i++)
            {
                count += ceil((double)nums[i] / mid);
            }
            if(count <= threshold)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        long long high = 0;
        int ans = 0;

        for(int i = 0 ; i < weights.size() ; i++)
        {
            low = max(low , weights[i]);
            high += weights[i];
        }

        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int day = 1;
            int load = 0;
            for(int i = 0 ; i < weights.size() ; i++)
            {
                if(load + weights[i] > mid)
                {
                    day++;
                    load = weights[i];
                }
                else{
                    load += weights[i];
                }
            
            }
            if(day <= days)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
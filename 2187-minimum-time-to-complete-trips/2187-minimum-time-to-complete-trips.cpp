class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = INT_MAX;
        long long high = 0;
        long long totalbus = 0;
        long long ans = LLONG_MAX;
        for(int i = 0 ; i < time.size() ; i++)
        {
            low = min(low , (long long)time[i]);
        }
        high = low*totalTrips;

        while(low <= high)
        {
            long long mid = low+(high-low)/2;
            totalbus = 0;
            for(long long i = 0 ; i < time.size() ; i++)
            {
                totalbus += mid/time[i];
            }
            if(totalbus >= totalTrips)
            {
                high = mid-1;
                ans = min(ans , mid);
            }
            else low = mid+1;
        }

        return ans;
    }
};
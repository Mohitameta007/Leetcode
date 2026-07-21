class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = 1;
        int high = INT_MIN;
        int ans = -1;
        for(int i = 0 ; i < bloomDay.size() ; i++)
        {
            high = max(high , bloomDay[i]);
        }

        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int flower = k;
            int count = 0;
            for(int i = 0 ; i < bloomDay.size() ; i++)
            {
                if(mid >= bloomDay[i]) flower--;
                else flower = k;
                if(flower == 0)
                {
                    count++;
                    flower = k;
                }
            }
            if(count >= m){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        long long ans = 0 ;
        vector<int> prefixgcd;
        int maxi = nums[0];

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] > maxi) maxi = nums[i];
            int temp = gcd(nums[i] , maxi);
            prefixgcd.push_back(temp);
        }

        sort(prefixgcd.begin() , prefixgcd.end());
        int start = 0;
        int end = prefixgcd.size()-1;
        while(start < end)
        {
            ans += gcd(prefixgcd[start] , prefixgcd[end]);
            start++;
            end--;
        }

        return ans;
    }
};
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int greatest = INT_MIN;
        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] > greatest) greatest = nums[i];
            if(nums[i] < smallest) smallest = nums[i];
        }
        ans = gcd(smallest , greatest);

        return ans;
    }
};
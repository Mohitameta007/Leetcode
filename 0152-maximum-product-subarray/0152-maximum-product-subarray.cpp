class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftmax = 1;
        int rightmax = 1;
        int ans = INT_MIN;

        int i = 0;
        int j = nums.size()-1;
        while(i < nums.size())
        {
            leftmax = nums[i++]*leftmax;
            rightmax = nums[j--]*rightmax;
            ans = max(ans , max(leftmax , rightmax));
            if(leftmax == 0) leftmax = 1;
            if(rightmax == 0) rightmax = 1;
        }

        return ans;
    }
};
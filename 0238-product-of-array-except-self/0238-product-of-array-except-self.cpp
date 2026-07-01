class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> ans;
        int count = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0)
            {
                product = product*1;
                count++;
            }
            else product *= nums[i];
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0 && count > 1)
            {
                ans.push_back(0);
            }
            else if(nums[i] == 0 && count > 0)
            {
                ans.push_back(product);
            }
            else if(nums[i] != 0 && count > 0)
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(product/nums[i]);
            }
        }

        return ans;
    }
};
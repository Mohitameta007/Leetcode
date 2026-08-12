class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j < nums.size())
        {
            auto it = mpp.find(nums[j]);
            if(it == mpp.end() || it->second < k)
            {
                mpp[nums[j]]++;
                j++;
                ans = max(ans , j-i);
            }
            else{
                mpp[nums[i]]--;
                i++;
            }
        }

        return ans;
    }
};
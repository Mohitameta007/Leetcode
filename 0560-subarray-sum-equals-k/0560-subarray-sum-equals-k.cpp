class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        int count = 0;
        int sum = 0;
        mpp[0] = 1;

        for(int i = 0 ; i < nums.size() ; i++)
        {  
            sum += nums[i];
            auto it = mpp.find(sum-k);
            if(it != mpp.end())
            {
                count += it->second;
            }
            mpp[sum]++;
        }
        return count;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            auto it = mpp.find(nums[i]);

            if(it == mpp.end())
            {
                mpp[nums[i]] = i;
            } 
            else
            {
                if(abs(i - it->second) <= k) return true;
                else mpp[nums[i]] = i;
            }
        }
        return false;
    }
};
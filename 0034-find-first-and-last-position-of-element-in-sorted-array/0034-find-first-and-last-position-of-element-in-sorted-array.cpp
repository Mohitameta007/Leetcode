class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return{-1,-1};
        int first = 0;
        int last = 0;

        auto it = lower_bound(nums.begin() , nums.end() , target);
        int indx = it-nums.begin();

        if(indx >= nums.size() || nums[indx] != target) return{-1,-1};
        else{
            first = it-nums.begin();
            auto it2 = upper_bound(nums.begin() , nums.end() , target);
            last = it2-nums.begin()-1;
        }

        vector<int> ans = {first , last};
        return ans;
    }
};
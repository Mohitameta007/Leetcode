class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin() , nums.end() , target);
        int indx = it-nums.begin();

        if(indx < nums.size() && nums[indx] == target) return indx;
        else return -1;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int find = k;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == find)
            {
                find += k;
            }
            else if(nums[i] > find)
            {
                return find;
            }
        }

        return find;
    }
};
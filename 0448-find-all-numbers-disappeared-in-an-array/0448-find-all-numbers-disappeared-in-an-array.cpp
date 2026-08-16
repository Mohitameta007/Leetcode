class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin() , nums.end());
        int count = 1;
        int i = 0;

        while(i < nums.size())
        {
            if(count == nums[i])
            {
                i++;
                count++;
            }
            else if(count > nums[i]) i++;
            else{
                ans.push_back(count);
                count++;
            }
        }

        while(count <= nums.size())
        {
            ans.push_back(count);
            count++;
        }

        return ans;
    }
};
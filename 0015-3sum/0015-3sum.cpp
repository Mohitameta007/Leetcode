class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int dupli = INT_MIN;
        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size()-2 ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int j = i+1;
            int k = nums.size()-1;
            while(j < k)
            {
                if(nums[i]+nums[j]+nums[k] < 0) j++;
                else if(nums[i]+nums[j]+nums[k] > 0) k--;
                else{
                    temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    while( j < k && nums[j] == temp[1])
                    {
                        j++;
                    }
                    while(k > j && nums[k] == temp[2])
                    {
                        k--;
                    }
                    dupli = nums[i];
                }
            }
        }

        return ans;
    }
};
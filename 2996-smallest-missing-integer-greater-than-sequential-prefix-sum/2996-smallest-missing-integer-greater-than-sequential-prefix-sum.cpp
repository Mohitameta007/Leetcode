class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = 0;
        unordered_set<int> st;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            st.insert(nums[i]);
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == nums.size()-1) 
            {
                sum += nums[i];
                break;
            }
            if(nums[i] == nums[i+1]-1)
            {
                sum += nums[i];
                continue;
            }
            sum += nums[i];
            break;
        }

        while(1)
        {
            if(st.find(sum) == st.end()) return sum;
            else sum++;
        }

        return sum;
    }
};
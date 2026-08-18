class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int start = 0;
        int end = k-1;
        unordered_map <int , int>mpp;
        int ans = -1;
        int count = INT_MAX;

        while(end < nums.size())
        {
            unordered_set <int> st;
            for(int i = start ; i <= end ; i++)
            {
                st.insert(nums[i]);
            }
            for(auto it : st)
            {
                mpp[it]++;
            }
            start++;
            end++;
        }
        for(auto it : mpp)
        {
            if(it.second == 1 && ans < it.first)
            {
                ans = it.first;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        unordered_set<int> nst;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i ; j < nums.size() ; j++)
            {
                int xr = nums[i]^nums[j];
                st.insert(xr);
            }
        }
        for(int k = 0 ; k < nums.size() ; k++)
        {
            for(auto it : st)
            {
                int xr = it^nums[k];
                nst.insert(xr);
            }
        }

        int ans = nst.size();
        return ans;
    }
};

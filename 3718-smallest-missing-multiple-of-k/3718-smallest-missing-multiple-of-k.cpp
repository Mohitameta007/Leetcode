class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        int findno = k;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mpp[nums[i]]++;
        }
        while(true)
        {
            auto it = mpp.find(findno);
            if(it == mpp.end()) return findno;
            else findno += k; 
        }

        return findno;
    }
};
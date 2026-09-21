class Solution {
public:

    void total(vector<int>&nums , vector<int>& temp , vector<bool>& used , set<vector<int>>& st)
    {
        if(temp.size() == 3)
        {
            st.insert(temp);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(used[i]) continue;

            if(temp.empty() && nums[i] == 0) continue;

            if((temp.size() < 2) || (temp.size() == 2 && nums[i]%2 == 0))
            {
                temp.push_back(nums[i]);
                used[i] = true;
                total(nums , temp , used , st);
                used[i] = false;
                temp.pop_back();
            } 
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size() , false);
        set<vector<int>> st;
        vector<int> temp;
        total(digits , temp , used , st);

        return st.size();
    }
};
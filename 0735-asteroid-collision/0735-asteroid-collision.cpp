class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        bool destroyed = false;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            destroyed = false;
            if(st.empty()) st.push(nums[i]);
            else if(nums[i] >= 0) st.push(nums[i]);
            else{
                while(!st.empty())
                {
                    if(st.top() > 0 && st.top()+nums[i] < 0) st.pop();
                    else if(st.top() + nums[i] > 0) 
                    {
                        destroyed = true;
                        break;
                    }
                    else if(st.top() + nums[i] == 0)
                    {
                        st.pop();
                        destroyed = true;
                        break;
                    } 
                    else
                    {
                        destroyed = true;
                        st.push(nums[i]);
                        break;
                    } 
                }
                if(!destroyed) st.push(nums[i]);
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }
};
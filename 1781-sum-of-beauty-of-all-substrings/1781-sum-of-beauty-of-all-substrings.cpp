class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            vector<int> v(26 , 0);
            for(int j = i ; j < s.size() ; j++)
            {
                v[s[j]-'a']++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto it : v)
                {
                    if(it > maxi) maxi = it;
                    if(it != 0 && it < mini) mini = it;
                }
                if(maxi != INT_MIN && mini != INT_MAX) ans += maxi-mini;
            }
        }

        return ans;
    }
};
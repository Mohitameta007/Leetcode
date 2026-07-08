class Solution {
public:
    vector<vector<int>> generate(int k) {
        vector<vector<int>> ans(k);
        ans[0].push_back ({1});
        if(k == 1) return ans;

        ans[1].push_back ({1});
        ans[1].push_back ({1});
        if(k == 2) return ans;

        for(int i = 2 ; i < k ; i++)
        {
            for(int j = 0 ; j < i+1 ; j++)
            {
                if(j == 0 || j == i) ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
        }

        return ans;

    }
};
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for(int i = 0 ; i < columnTitle.size() ; i++)
        {
            ans += columnTitle[i]-'A'+1;
            if(i+1 != columnTitle.size()) ans *= 26;
            else return ans;
        }
        return ans;
    }
};
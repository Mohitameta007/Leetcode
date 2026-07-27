class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int indx = 0;
        string ans = "";
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(') count++;
            else if(s[i] == ')') count--;
            ans += s[i];

            if(count == 0)
            {
                ans.erase(indx , 1);
                ans.pop_back();
                indx = ans.size();
            }
            i++;
        }

        return ans;
    }
};
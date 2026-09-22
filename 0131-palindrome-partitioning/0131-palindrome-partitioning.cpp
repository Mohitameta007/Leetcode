class Solution {
public:

    bool ispalindrome(string temp)
    {
        int start = 0;
        int end = temp.size()-1;
        while(start <= end)
        {
            if(temp[start] != temp[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(string s , int indx , vector<string>& temp , vector<vector<string>>& ans)
    {
        if(indx == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = indx ; i < s.size() ; i++)
        {
            string part = s.substr(indx , i-indx+1);
            if(ispalindrome(part)) 
            {
                temp.push_back(part);
                solve(s , i+1 , temp , ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int indx = 0;

        solve(s , indx , temp , ans);

        return ans;
    }
};
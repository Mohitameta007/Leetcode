class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int left = 0;
        int right = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            left = i-1;
            right = i+1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }

            int len = right-left-1;
            if(len > ans.size()) ans = s.substr(left+1 , len);

            left = i;
            right = i+1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }

            len = right-left-1;
            if(len > ans.size()) ans = s.substr(left+1 , len);
        }

        return ans;
    }
};
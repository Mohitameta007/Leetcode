class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        string ans = "";
        int maxlen = 1;
        pair<int , int> p = {0 , 0};
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            left = i-1;
            right = i+1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                if(right-left+1 > maxlen) 
                {
                    maxlen = right-left+1;
                    p = {left , right};
                }

                if(left-1 < 0 && right+1 >= s.size()) break;
                else{
                    left--;
                    right++;
                }
            }

            left = i;
            right = i+1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                if(right-left+1 > maxlen) 
                {
                    maxlen = right-left+1;
                    p = {left , right};
                }

                if(left-1 < 0 && right+1 >= s.size()) break;
                else{
                    left--;
                    right++;
                }
            }
        }

        for(int i = p.first ; i <= p.second ; i++)
        {
            ans += s[i];
        }

        return ans;
    }
};
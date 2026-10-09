class Solution {
public:
    int countSubstrings(string s) {
        int left = 0;
        int right = 0;
        int count = 0;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            left = i-1;
            right = i+1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
                count++;
            }

            left = i;
            right = i+1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
                count++;
            }

            count++;
        }

        return count;
    }
};
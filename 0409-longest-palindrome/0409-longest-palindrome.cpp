class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        int maxodd = 0;
        int ans = 0;
        int odd = 0;

        for (char c : s)
        {
            freq[c]++;
        }

        for(int x : freq)
        {
            if(x % 2 != 0)
            {
                ans += x-1;
                odd = 1;
            } 
            else ans += x;
        }
        ans += odd;

        return ans;
    }
};
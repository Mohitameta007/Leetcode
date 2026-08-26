class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int mini = INT_MAX;
        int count = 0;
        int low = 0;
        int high = 0;
        int indx = 0;

        while(high < s.size())
        {
            if(count < k)
            {
                if(s[high] == '1') count++;
                high++;
            } 
        while(count == k)
        {
            string cur = s.substr(low, high - low);
            if(high - low < mini || (high - low == mini && cur < ans))
            {
                mini = high - low;
                ans = s.substr(low, high - low);
            }

            if(s[low] == '1')
                count--;

            low++;
        }       
        }
        return ans;
    }
};
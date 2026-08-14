class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char , int> mpp;
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < s.size())
        {
            auto it = mpp.find(s[j]);
            if(it == mpp.end() || it->second < 2)
            {
                mpp[s[j]]++;
                j++;
            }
            else{
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans , j-i);
        }
        return ans;

    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;
        unordered_set<char> st;

        while(end < s.size())
        {
            if(st.find(s[end]) == st.end())
            {
                st.insert(s[end]);
                end++;
            }
            else{
                while(start < end && s[start] != s[end])
                {
                    st.erase(s[start]);
                    start++;
                }
                st.erase(s[start]);
                start++;
            }
            ans = max(ans , end-start);
        }

        return ans;
    }
};
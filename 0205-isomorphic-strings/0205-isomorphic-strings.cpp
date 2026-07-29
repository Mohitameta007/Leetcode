class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char , char> mpp;
        unordered_set<char> st;
        if(s.size() != t.size()) return false;

        for(int i = 0 ; i < s.size() ; i++)
        {
            auto it = mpp.find(s[i]);
            if(it == mpp.end())
            {
                if(st.find(t[i]) == st.end())
                {
                    mpp[s[i]] = t[i];
                    st.insert(t[i]);
                }
                else return false;
            }
            else{
                if(it->first == s[i] && it->second != t[i]) return false;
            }
        }

        return true;
    }
};
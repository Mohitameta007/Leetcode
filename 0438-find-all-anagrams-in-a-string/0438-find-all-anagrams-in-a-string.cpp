class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> ss(256 , 0);
        vector<int> pp(256 , 0);
        int start = 0;
        int end = 0;

        for(int i = 0 ; i < p.size() ; i++)
        {
            pp[p[i]]++;
        }

        while(end < p.size())
        {
            ss[s[end]]++;
            end++;
        }
        if(ss == pp) ans.push_back(start);
        while(end < s.size())
        {
            ss[s[end]]++;
            end++;
            ss[s[start]]--;
            start++;

            if(ss == pp) ans.push_back(start);
        }

        return ans;
    }
};
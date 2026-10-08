class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int start = 0;
        int end = 0;
        vector<int> v1(256 , 0);
        vector<int> v2(256 , 0);

        for(int i = 0 ; i < s1.size() ; i++)
        {
            v1[s1[i]]++;
        }

        while(end < s1.size())
        {
            v2[s2[end]]++;
            end++;
        }
        if(v1 == v2) return true;

        while(end < s2.size())
        {
            v2[s2[end]]++;
            v2[s2[start]]--;
            end++;
            start++;
            if(v1 == v2) return true;
        }
        return false;
    }
};
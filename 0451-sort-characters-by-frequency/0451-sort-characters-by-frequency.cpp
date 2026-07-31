class Solution {
public:
    string frequencySort(string s) {
        vector<string> bucket(s.size()+1);
        unordered_map <char , int> freq;
        string ans = "";

        for(auto ch : s)
        {
            freq[ch]++;
        }

        for(auto it : freq)
        {
            bucket[it.second] += it.first;
        }

        for(int i = bucket.size()-1 ; i > 0 ; i--)
        {
            for(auto ch : bucket[i])
            {
                ans += string(i , ch);
            }
        }
        return ans;

    }
};
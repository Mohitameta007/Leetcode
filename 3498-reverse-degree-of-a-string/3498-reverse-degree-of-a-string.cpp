class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char , int> mpp;
        int val = 26;
        int sum = 0;

        for(int i = 0 ; i < 26 ; i++)
        {
            mpp[97+i] = val;
            val--;
        }

        for(int i = 0 ; i < s.size() ; i++)
        {
            auto it = mpp.find(s[i]);
            sum += (it->second)*(i+1);
        }

        return sum;
    }
};
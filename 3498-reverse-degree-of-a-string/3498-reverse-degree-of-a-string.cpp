class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            int diff = s[i]-'a';
            sum += (26-diff)*(i+1);
        }

        return sum;
    }
};
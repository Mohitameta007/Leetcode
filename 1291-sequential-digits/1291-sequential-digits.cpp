class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;
        int count = 0;
        int lower = low;
        while(lower > 0)
        {
            lower /= 10;
            count++;
        }

        string s = "123456789";
        int start = 0;
        int end = count-1;
        long long anss = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            for(int j = i ; j < s.size() ; j++)
            {
                anss *= 10;
                anss += s[j]-'0';
                if(anss >= low && anss <= high) ans.push_back(anss);
            }
            anss = 0;
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};
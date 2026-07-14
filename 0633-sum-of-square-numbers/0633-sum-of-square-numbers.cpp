class Solution {
public:
    bool judgeSquareSum(int c) {
        int low = 0;
        int high = floor(sqrt(c));

        while(high >= low)
        {
            long long sq = 1LL * low * low + 1LL * high * high;

            if(sq == c) return true;
            else if(sq < c) low++;
            else high--; 
        }

        return false;
    }
};
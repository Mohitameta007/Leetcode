class Solution {
public:

    // int length(int n , int len)
    // {
    //     if(n < 1) return len;
    //     return length(n/10 , len+1);
    // }

    int countCommas(int n) {
        int count = 0;
        for(int i = 1000 ; i <= n ; i++)
        {
            count++;
        }
        return count;
    }
};
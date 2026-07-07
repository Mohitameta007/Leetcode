class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long ans = 0;
        int mul = 0;
        int count = 0;
        while(n > 0)
        {
            int num = n%10;
            if(num != 0)
            {
                ans += num * pow(10 , count);
                mul += num;
                count++;
            }
            n /= 10;
        }

        return ans*mul;
    }
};
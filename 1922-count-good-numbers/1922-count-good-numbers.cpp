class Solution {
public:

    int solveeven(int base , long long n)
    {
        if(n == 0) return 1;
        long long half = (solveeven(base , n/2))%1000000007;
        if(n % 2 == 0) return (half*half)%1000000007;
        else return (half*half*base)%1000000007;
    }

    int solveodd(int base , long long n)
    {
        if(n == 0) return 1;
        long long half = (solveodd(base , n/2))%1000000007;
        if(n % 2 == 0) return (half*half)%1000000007;
        else return (half*half*base)%1000000007;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 0) 
        {
            int even = n/2;
            int odd = n/2;
            return ((1LL*solveeven(5 , n/2)%1000000007) * (1LL*solveodd(4 , n/2)%1000000007))%1000000007;
        }
        else{
            int even = (n/2)+1;
            int odd = n/2;
            return ((1LL*solveeven(5 , (n/2)+1)%1000000007) * (1LL*solveodd(4 , n/2)%1000000007))%1000000007;
        }
        return 1;
    }
};
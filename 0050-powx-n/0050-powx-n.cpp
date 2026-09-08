class Solution {
public:

    double power(double x , int n)
    {
        if(n == 0) return 1;

        double half = power(x , n/2);

        if(n % 2 == 0) return half*half;
        return half*half*x;   
    }

    double myPow(double x, int n) {
        if(n < 0) return 1/power(x , n);
        return power(x , n);
    }
};
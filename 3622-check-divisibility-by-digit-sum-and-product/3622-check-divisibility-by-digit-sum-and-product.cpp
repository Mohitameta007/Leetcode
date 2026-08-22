class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int num = n;

        while(num > 0)
        {
            int dig = num%10;
            sum += dig;
            product *= dig;
            num /= 10;
        }

        if(n % (sum + product) == 0) return true;
        return false;
    }
};
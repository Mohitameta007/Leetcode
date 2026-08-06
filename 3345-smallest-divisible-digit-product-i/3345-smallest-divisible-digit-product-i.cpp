int product_of_no(int k)
{
    int ans = 1;
    while(k > 0)
    {
        int dig = k%10;
        k = k/10;
        ans *= dig;
    }
    return ans;
}

class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true)
        {
            int product = product_of_no(n);
            if(product % t == 0) return n;
            else n++;
        }

        return 0;
    }
};
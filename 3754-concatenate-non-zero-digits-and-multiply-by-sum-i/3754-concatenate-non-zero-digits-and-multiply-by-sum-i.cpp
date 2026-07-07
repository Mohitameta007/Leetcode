class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> ans;
    
        while(n > 0)
        {
            int num = n % 10;
            if(num != 0)
            {
                ans.push_back(num);
            }
            n = n/10;
        }
        long long mul = 0;
        long long result = 0;
        int count = 0;
        for(int i = 0 ; i < ans.size() ; i++)
        {
            mul += ans[i];
            result += ans[i] * pow(10 , count);
            count++;
        }

        result = mul * result;

        return result;



    }
};
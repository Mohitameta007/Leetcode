string output(int n)
{
    if(n % 3 == 0 && n % 5 == 0) return "FizzBuzz";
    else if(n % 3 == 0) return "Fizz";
    else if(n % 5 == 0) return "Buzz";
    else return to_string(n);
}

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        int i = 1;
        while(i <= n)
        {
            string result = output(i);
            ans.push_back(result);
            i++;
        }

        return ans;
    }
};
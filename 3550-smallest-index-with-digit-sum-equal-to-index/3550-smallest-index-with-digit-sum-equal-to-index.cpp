class Solution {
public:

    int sumnum(int x)
    {
        int sum = 0;
        while(x > 0)
        {
            sum += x%10;
            x /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] > 9)
            {
                int res = sumnum(nums[i]);
                if(i == res) return i;
            }

            else{
                if(nums[i] == i) return i;
            }
        }

        return -1;
    }
};
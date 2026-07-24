class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int power = 0;
        int x = nums.size();
        if(x == 1) return 1;
        if(x == 2) return 2;

        while(x > 1)
        {
            x /= 2;
            power++;
        }

        return pow(2 , power+1);
    }
};
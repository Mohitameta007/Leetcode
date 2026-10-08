class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int>mpp;
        int start = 0;
        int end = 0;
        int ans = 0;

        while(end < fruits.size())
        {
            mpp[fruits[end]]++;
            end++;

            while(mpp.size() > 2)
            {
                mpp[fruits[start]]--;
                if(mpp[fruits[start]] == 0) mpp.erase(fruits[start]);
                start++;
            }

            ans = max(ans , end-start);
        }

        return ans;
    }
};
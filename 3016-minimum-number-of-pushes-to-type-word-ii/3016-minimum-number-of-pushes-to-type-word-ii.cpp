class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freqe(26 , 0);
        int ans = 0;

        for(int i = 0 ; i < word.size() ; i++)
        {
            freqe[word[i]-'a']++;
        }

        sort(freqe.begin() , freqe.end());
        reverse(freqe.begin() , freqe.end());

        for(int i = 0 ; i < freqe.size() ; i++)
        {
            if(freqe[i] > 0)
            {
                int cost = (i/8)+1;
                ans += cost*freqe[i];
            }
        }

        return ans;
    }
};
class Solution {
public:

    void allsubseq(int n , vector<string>& ans , string news)
    {
        if(n == news.size())
        {
            ans.push_back(news);
            return;
        }

        news += "1";
        allsubseq(n , ans , news);

        news.pop_back();
        if(!news.empty() && news.back() == '0') return;
        news += "0";
        allsubseq(n , ans , news);

    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string news = "";
        allsubseq(n , ans , news);

        return ans;
    }
};
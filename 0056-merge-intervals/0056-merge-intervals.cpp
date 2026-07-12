class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 0 ; i < intervals.size()-1 ; i++)
        {
            if(end >= intervals[i+1][0])
            {
                end = max(end , intervals[i+1][1]);
            }
            else{
                ans.push_back({start , end});
                start = intervals[i+1][0];
                end = intervals[i+1][1];
            }
        }
        ans.push_back({start , end});

        return ans;
    }
};
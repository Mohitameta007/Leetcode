class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int start = newInterval[0];
        int end = newInterval[1];

        int i = 0;

        // Pehle wale intervals add karo
        while(i < intervals.size() && intervals[i][1] < start)
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // Overlapping intervals merge karo
        while(i < intervals.size() && intervals[i][0] <= end)
        {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        ans.push_back({start, end});

        // Baaki intervals add karo
        while(i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
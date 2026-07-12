class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return arr;
        unordered_map<int , int> mpp;
        vector<int> copy(arr.begin() , arr.end());
        sort(copy.begin() , copy.end());
        int rank = 1;

        for(int i = 0 ; i < copy.size()-1 ; i++)
        {
            if(copy[i] == copy[i+1])
            {
                mpp[copy[i]] = rank;
            }
            else
            {
                mpp[copy[i]] = rank;
                rank++;
            }
        }
        mpp[copy[copy.size()-1]] = rank;

        for(int i = 0 ; i < arr.size() ; i++)
        {
            auto it = mpp.find(arr[i]);
            arr[i] = it->second;
        }

        return arr;
    }
};
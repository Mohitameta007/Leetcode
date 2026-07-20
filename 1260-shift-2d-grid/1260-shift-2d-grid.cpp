class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr;
        vector<vector<int>> ans;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        int rotate = k % (row*col);

        reverse(arr.begin() , arr.end());
        reverse(arr.begin() , arr.begin()+rotate);
        reverse(arr.begin()+rotate , arr.end());

        vector<int> temp;
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            temp.push_back(arr[i]);

            if(temp.size() == col)
            {
                ans.push_back(temp);
                temp.clear();
            }
        }

        return ans;
    }
};
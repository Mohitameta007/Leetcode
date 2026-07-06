class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = i ; j < matrix[0].size() ; j++)
            {
                if(i != j)
                {
                    swap(matrix[j][i] , matrix[i][j]);
                }
            }
        }
        int start = 0;
        int end = matrix[0].size()-1;

        for(int i = 0 ; i < matrix.size() ; i++)
        {
            while(start < end)
            {
                swap(matrix[i][start] , matrix[i][end]);
                start++;
                end--;
            }
            start = 0;
            end = matrix[0].size()-1;
        }
    }
};
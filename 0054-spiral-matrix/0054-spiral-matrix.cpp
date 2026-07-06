class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0;
        int bottom = row-1;
        int left = 0;
        int right = col-1;

        while(top <= bottom && left <= right)
        {
            for(int i = left ; i <= right ; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            for(int i = top+1 ; i <= bottom ; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            if(top < bottom)
            {
                for(int i = right-1 ; i >= left ; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            if(left < right)
            {
                for(int i = bottom-1 ; i > top ; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
            }

            top++;
            bottom--;
            right--;
            left++;
        }

        return ans;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size() * matrix[0].size();
        int low = 0;
        int high = size-1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();

            if(matrix[row][col] > target) high = mid-1;
            else if(matrix[row][col] < target) low = mid+1;
            else return true;
        }

        return false;
    }
};
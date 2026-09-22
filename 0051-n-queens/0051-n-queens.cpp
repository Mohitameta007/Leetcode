class Solution {
public:

    bool isvalid(int n , vector<vector<char>>& board , int row , int col)
    {
        int rightcol = col+1;
        int leftcol = col-1;
        if(row == 0) return true;
        else{
            for(int i = row-1 ; i >= 0 ; i--)
            {
                if(board[i][col] == 'Q') return false;
            }
            for(int i = row-1 ; i >= 0 ; i--)
            {
                if(leftcol < 0) break;
                if(board[i][leftcol] == 'Q') return false;
                leftcol--;
            }
            for(int i = row-1 ; i >= 0 ; i--)
            {
                if(rightcol >= n) break;
                if(board[i][rightcol] == 'Q') return false;
                rightcol++;
            }
            return true;
        }
        return true;
    }

    void queens(int n , int row , vector<vector<char>>& board , vector<vector<string>>& ans)
    {
        if(row == n)
        {
            vector<string> temp;
        
            for(int i = 0; i < n; i++)
            {
                string s(board[i].begin(), board[i].end());
                temp.push_back(s);
            }
        
            ans.push_back(temp);
            return;
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(isvalid(n , board , row , i))
            {
                board[row][i] = 'Q';
                queens(n , row+1 , board , ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int row = 0;
        int col = 0;
        queens(n , row , board , ans);

        return ans;
    }
};
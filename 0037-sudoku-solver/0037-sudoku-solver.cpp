class Solution {
public:

    bool isvalid(vector<vector<char>>& board , char n , int row , int col)
    {
        for(int i = 0 ; i < board.size() ; i++)
        {
            if(board[row][i] == n) return false;
        }
        for(int i = 0 ; i < board.size() ; i++)
        {
            if(board[i][col] == n) return false;
        }

        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;

        for(int i = startrow ; i < startrow+3 ; i++)
        {
            for(int j = startcol ; j < startcol+3 ; j++)
            {
                if(board[i][j] == n) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int r = 0 ;  r < 9 ; r++)
        {
            for(int c = 0 ; c < 9 ; c++)
            {
                if(board[r][c] == '.')
                {
                    for(char i = '1' ; i <= '9' ; i++)
                    {
                        if(isvalid(board , i , r , c))
                        {
                            board[r][c] = i;
                            if(solve(board)) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};
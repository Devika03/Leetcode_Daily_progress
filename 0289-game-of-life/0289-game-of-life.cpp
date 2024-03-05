class Solution {
public:
    int countAliveNeighbors(vector<vector<int>>& board, int row, int col)
    {
        int count=0;
        int m = board.size();
        int n = board[0].size();
        int drow[]={-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i =0 ; i<8 ; i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 1)
            count++;
        }
        return count;
        }
    

    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>bs1(m,vector<int>(n, 0));
        for(int i =0 ; i< m ; i++)
        {
            for(int j = 0 ; j< n ; j++)
            {
                if(board[i][j]==0)
                {
                    int count = countAliveNeighbors(board, i, j);
                    if (count==3) bs1[i][j]=1;
                }
                else if (board[i][j]==1)
                {
                    int count = countAliveNeighbors(board,i,j);
                    if(count<2)
                    {
                        bs1[i][j]=0;
                    }
                    else if (count==2 || count==3) bs1[i][j]=1;
                    else if (count>3) bs1[i][j]=0;
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i][j] = bs1[i][j];
            }
        }
    }
};
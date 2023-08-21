class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O')
                {
                    cout<<i<<j<<" ";
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                
        while(!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++)
            {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                
                if(newRow>=0 && newCol>=0 && newRow<n && newCol<m)
                    if(!visited[newRow][newCol] && board[newRow][newCol]=='O')
                    {
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = 1;
                    }
                }
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!visited[i][j] && board[i][j]=='O')
                    board[i][j] = 'X';
    }
    
    
};
class Solution {
private:
    int m, n;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    
    int bfs(vector<vector<char>>& grid)
    {
        queue<pair<int, int>>q;
       
        
        return 0;
    }
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
        for(int i=0; i<4; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            
            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n)
                if(!visited[newRow][newCol] && grid[newRow][newCol]=='1')
                {
                    dfs(grid, newRow, newCol, visited);
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int ans=0;
        vector<vector<int>>visited(m, vector<int>(n, 0));  
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == '1' && !visited[row][col])
                {
                    ans++;cout<<row<<" "<<col;
                    dfs(grid, row, col, visited);
                }
            }
        }
        return ans;
    }
};
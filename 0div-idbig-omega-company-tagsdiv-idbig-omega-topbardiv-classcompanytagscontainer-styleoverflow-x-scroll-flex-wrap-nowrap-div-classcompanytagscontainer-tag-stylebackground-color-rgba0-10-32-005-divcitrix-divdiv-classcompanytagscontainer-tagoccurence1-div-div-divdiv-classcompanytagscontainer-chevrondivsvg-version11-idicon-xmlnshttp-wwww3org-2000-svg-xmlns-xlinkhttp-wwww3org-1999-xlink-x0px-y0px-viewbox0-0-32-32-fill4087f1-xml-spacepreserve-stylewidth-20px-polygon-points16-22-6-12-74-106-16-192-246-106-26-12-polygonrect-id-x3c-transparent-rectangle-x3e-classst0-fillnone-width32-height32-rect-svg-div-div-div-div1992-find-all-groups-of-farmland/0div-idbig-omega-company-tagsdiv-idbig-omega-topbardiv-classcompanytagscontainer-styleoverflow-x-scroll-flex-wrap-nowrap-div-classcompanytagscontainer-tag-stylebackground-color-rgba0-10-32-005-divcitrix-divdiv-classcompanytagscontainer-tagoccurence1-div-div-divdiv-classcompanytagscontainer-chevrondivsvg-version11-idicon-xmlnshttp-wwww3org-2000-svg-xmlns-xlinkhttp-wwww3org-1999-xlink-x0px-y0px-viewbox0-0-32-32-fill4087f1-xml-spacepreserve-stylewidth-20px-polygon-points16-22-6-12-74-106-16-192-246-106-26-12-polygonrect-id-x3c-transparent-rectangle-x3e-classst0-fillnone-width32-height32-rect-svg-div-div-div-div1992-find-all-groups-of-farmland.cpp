class Solution {
private:
    int m, n;
    vector<vector<int>>visited;
    vector<vector<int>>ans;
    
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& land, int row, int col, int &r2, int& c2)
    {
        visited[row][col] = 1;
        
        for(int i=0; i<4; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            
            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n)
            {
                if(!visited[newRow][newCol] && land[newRow][newCol]==1)
                {
                    r2 = max(r2, newRow);
                    c2 = max(c2, newCol);
                    dfs(land, newRow, newCol, r2, c2);
                }
            }
        }
        return;
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        visited.resize(m, vector<int>(n, 0));
        
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(land[row][col]==1 && !visited[row][col])
                {
                    int r1 = row, c1 = col;
                    int r2 = row, c2 = col;
                    dfs(land, row, col, r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                    
                }
            }
        }
        return ans;
    }
};
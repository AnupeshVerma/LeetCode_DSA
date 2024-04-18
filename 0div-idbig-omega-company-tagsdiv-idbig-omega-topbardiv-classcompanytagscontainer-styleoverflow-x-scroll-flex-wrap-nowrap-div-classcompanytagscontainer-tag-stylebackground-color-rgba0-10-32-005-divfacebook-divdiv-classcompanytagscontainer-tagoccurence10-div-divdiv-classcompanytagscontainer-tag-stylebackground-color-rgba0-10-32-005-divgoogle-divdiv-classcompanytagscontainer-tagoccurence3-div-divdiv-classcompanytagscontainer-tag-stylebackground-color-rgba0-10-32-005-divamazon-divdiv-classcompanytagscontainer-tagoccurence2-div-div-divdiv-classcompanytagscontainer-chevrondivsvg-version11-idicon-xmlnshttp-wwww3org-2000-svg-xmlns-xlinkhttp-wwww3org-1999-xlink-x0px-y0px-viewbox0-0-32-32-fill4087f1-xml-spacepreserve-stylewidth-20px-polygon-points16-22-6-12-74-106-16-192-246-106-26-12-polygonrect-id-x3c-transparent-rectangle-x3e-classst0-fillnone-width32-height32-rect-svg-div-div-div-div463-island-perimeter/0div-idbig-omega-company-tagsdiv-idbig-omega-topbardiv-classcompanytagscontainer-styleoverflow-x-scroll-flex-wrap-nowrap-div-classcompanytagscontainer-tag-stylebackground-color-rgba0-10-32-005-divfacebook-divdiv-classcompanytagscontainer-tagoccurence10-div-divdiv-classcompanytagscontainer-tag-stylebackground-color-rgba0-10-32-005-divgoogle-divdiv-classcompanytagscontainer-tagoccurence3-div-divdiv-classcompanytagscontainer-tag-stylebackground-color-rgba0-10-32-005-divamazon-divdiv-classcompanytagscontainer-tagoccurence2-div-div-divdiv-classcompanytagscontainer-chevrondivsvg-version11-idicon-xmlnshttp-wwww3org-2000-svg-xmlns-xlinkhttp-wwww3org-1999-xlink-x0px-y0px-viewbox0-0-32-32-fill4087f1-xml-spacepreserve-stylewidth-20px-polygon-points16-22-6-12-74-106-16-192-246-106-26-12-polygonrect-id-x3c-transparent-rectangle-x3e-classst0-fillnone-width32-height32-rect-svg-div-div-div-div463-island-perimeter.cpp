class Solution {
private:
    int bruteForce(vector<vector<int>>& grid, int n, int m)
    {
        int perimeter = 0;
        
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(grid[row][col] == 1)
                {
                    int connections = 0;
                    if(row>0   and grid[row-1][col]==1) connections++;
                    if(col>0   and grid[row][col-1]==1) connections++;
                    if(row<n-1 and grid[row+1][col]==1) connections++;
                    if(col<m-1 and grid[row][col+1]==1) connections++;
                    perimeter += (4 - connections);
                }
            }
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return bruteForce(grid, n, m);
    }
};
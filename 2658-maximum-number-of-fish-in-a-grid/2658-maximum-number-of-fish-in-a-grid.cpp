class Solution {
private:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    int maxFish(vector<vector<int>>& grid, int srow, int scol, int rows, int cols) {
        int ans = grid[srow][scol];

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[srow][scol] = true;

        queue<pair<int, int>>q;
        q.push({srow, scol});

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                

                if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols) {
                    if(grid[newRow][newCol] != 0 && !visited[newRow][newCol]) {
                        ans += grid[newRow][newCol];
                        cout<<ans<<" ";
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }


public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        
        vector<pair<int, int>> water;
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(grid[row][col] != 0)
                    water.push_back({row, col});
            }
        }

        for(auto w : water) {
            auto [row, col] = w;
            ans = max(ans, maxFish(grid, row, col, rows, cols));
        }
        return ans;
    }
};
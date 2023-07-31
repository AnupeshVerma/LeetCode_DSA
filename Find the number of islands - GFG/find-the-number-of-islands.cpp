//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<char>>&grid, vector<vector<int>>&visited, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        
        for(int i=-1; i<=1; i++)
            for(int j=-1; j<=1; j++)
            {
                int newRow = row+i;
                int newCol = col+j;
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]=='1')
                    dfs(grid, visited, newRow, newCol);
            }
    }
    
    void bfs(vector<vector<char>>&grid, vector<vector<int>>&visited, int row, int col)
    {
        
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        
        queue<pair<int,int>>q;
        q.push({row, col});
        
        while(!q.empty())
        {
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++)
                for(int j=-1; j<=1; j++)
                {
                    int newRow = row+i;
                    int newCol = col+j;
                    
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]=='1')
                    {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
            }    
            
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        int islands = 0;
        
        for(int row=0; row<n; row++)
            for(int col=0; col<m; col++)
            {
                if(!visited[row][col] && grid[row][col]=='1')
                    {
                        islands++;
                        bfs(grid, visited, row, col);
                        // dfs(grid, visited, row, col);
                    }
            }
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
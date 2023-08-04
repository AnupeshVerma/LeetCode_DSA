//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>>&grid, vector<pair<int, int>>&vec, vector<vector<int>>&visited, int row0, int col0, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        
        vec.push_back({row0-row, col0-col});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i=0; i<4; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]==1)
                dfs(grid, vec, visited, row0, col0, newRow, newCol);
            
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    dfs(grid, vec, visited, i, j, i, j);
                    st.insert(vec);
                }
            }
            
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
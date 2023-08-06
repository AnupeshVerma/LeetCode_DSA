//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int srcRow = source.first, srcCol = source.second;
        int destRow = destination.first, destCol = destination.second;
        if(srcRow==destRow && srcCol==destCol)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, pair<int, int>>>q;
        vector<vector<int>>dist(n, vector<int>(m, 1e8));
        dist[srcRow][srcCol] = 0;
        q.push({0,{srcRow, srcCol}});
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++)
            {
                int newRow = row+drow[i];
                int newCol = col+dcol[i];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && dis+1 < dist[newRow][newCol])
                {
                    if(newRow==destRow && newCol==destCol)
                        return dis+1;
                        
                    dist[newRow][newCol] = dis+1;
                    q.push({dis+1, {newRow, newCol}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
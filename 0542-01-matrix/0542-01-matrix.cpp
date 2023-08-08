class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>>q;
        vector<vector<int>>dist(n, vector<int>(m, 1e8));
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++)
            {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                
                if(newRow>=0 && newCol>=0 && newRow<n && newCol<m)
                    if(dist[newRow][newCol] > dist[row][col]+1)
                    {
                        dist[newRow][newCol] = dist[row][col]+1;
                        q.push({newRow, newCol});
                    }
            }
        }
        return dist;
        
    }
};
class Solution {
private:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        distance[0][0] = 0;

        while(!pq.empty()) {
            auto [minDist, cell] = pq.top();
            auto [row, col] = cell;
            pq.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m) {
                    int newDist = minDist + grid[newRow][newCol];
                    if(newDist < distance[newRow][newCol]) {
                        distance[newRow][newCol] = newDist;
                        pq.push({newDist, {newRow, newCol}});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};
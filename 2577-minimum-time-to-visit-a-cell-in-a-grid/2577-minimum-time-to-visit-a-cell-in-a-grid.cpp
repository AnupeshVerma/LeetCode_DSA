class Solution
{
    private:
        int drow[4] = { -1, 0, 1, 0};
        int dcol[4] = { 0, 1, 0, -1};

    public:
        int minimumTime(vector<vector < int>> &grid)
        {
            if (grid[0][1] > 1 && grid[1][0] > 1)
                return -1;

            int rows = grid.size(), cols = grid[0].size();
            priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            vector<vector <bool>> visited(rows, vector<bool> (cols, false));

            pq.push({0, {0, 0}});
            visited[0][0] = true;

            while(!pq.empty()) {
                auto [time, node] = pq.top();
                auto [row, col] = node;
                pq.pop();

                if(row == rows-1 && col == cols-1)
                    return time;
                
                for(int i=0; i<4; i++) {
                    int newRow = row + drow[i];
                    int newCol = col + dcol[i];

                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        int waitTime = (grid[newRow][newCol]-time)%2==0 ? 1 : 0;
                        int newTime = max(grid[newRow][newCol] + waitTime, time + 1);
                        pq.push({newTime, {newRow, newCol}});
                    }
                }
            }
        return -1;
        }
};
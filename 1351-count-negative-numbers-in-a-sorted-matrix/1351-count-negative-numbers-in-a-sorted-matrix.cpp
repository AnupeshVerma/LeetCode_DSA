class Solution {
private:
    int bruteForce(vector<vector<int>>& grid, int m, int n) {
        int count = 0;

        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] < 0)
                    count++;
            }
        }
        return count;
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return bruteForce(grid, m, n);
    }
};
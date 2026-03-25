class Solution {
private:
    int rows, cols;
    long int total_sum = 0;

    bool rowParition(vector<vector<int>>& grid) {
        // Calculte sum of each row and check
        long int row_sum = 0;
        for(int row=0; row<rows; row++) {
            for(int i=0; i<cols; i++)
                row_sum += grid[row][i];
            if(row_sum == total_sum/2)
                return true;
        }
        return false;
    }

    bool colParition(vector<vector<int>>& grid) {
        // Calculte sum of each row and check
        long int col_sum = 0;
        for(int col=0; col<cols; col++) {
            for(int i=0; i<rows; i++)
                col_sum += grid[i][col];
            if(col_sum == total_sum/2)
                return true;
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();

        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                this->total_sum += grid[row][col];
            }
        }
        // Sum should be even
        if(total_sum % 2 != 0)
            return false;

        return rowParition(grid) || colParition(grid);
    }
};
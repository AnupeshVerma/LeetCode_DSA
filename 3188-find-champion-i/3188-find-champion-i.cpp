class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();

        // Row which has all 1's except for i==j is the winner
        for(int row=0; row<n; row++){
            bool winner = true;
            for(int col=0; col<n; col++) {
                if(row == col)
                continue;

                // If any zero is found in the row, move to next row
                if(grid[row][col] == 0) {
                    winner = false;
                    break;
                }
            }
            if(winner)
                return row;
        } 
        return -1;
    }
};
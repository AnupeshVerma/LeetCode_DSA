class Solution {
private:
    int drow[4] = {0, 1, 0, -1};
    int dcol[4] = {1, 0, -1, 0};
    
    vector<vector<int>> spiralMatrix(int rows, int cols, int r, int c)
    {
        int totalElements = rows*cols;
        vector<vector<int>> ans;
        
        int dirIndex=0;
        for(int step=1; ans.size()<totalElements; step++)
        {
            // Increase step after every two direction change
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<step; j++)
                {
                    if(r>=0 && r<rows && c>=0 && c<cols )
                        ans.push_back({r, c});
                    r += drow[dirIndex];
                    c += dcol[dirIndex];
                }
                // Change direction
                dirIndex = (dirIndex+1)%4;
            }
        }
        return ans;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        return spiralMatrix(rows, cols, rStart, cStart);
    }
};
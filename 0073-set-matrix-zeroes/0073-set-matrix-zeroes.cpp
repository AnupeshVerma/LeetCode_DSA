class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
//         Check if any zero in first row
        for(int j=0; j<cols; j++)
            if(matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
//         Check if any zero in first row
        for(int i=0; i<rows; i++)
            if(matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        
//         Using first row and column as marker for others
        for(int i=1; i<rows; i++)
            for(int j=1; j<cols; j++)
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        
//         Make all marked rows to zero
        for(int i=1; i<rows; i++)
            if(matrix[i][0] == 0)
                for(int j=1; j<cols; j++)
                    matrix[i][j] = 0;
        
//         Make all marked columns to zero
        for(int j=1; j<cols; j++)
            if(matrix[0][j] == 0)
                for(int i=1; i<rows; i++)
                    matrix[i][j] = 0;
        
//         Make first row zero if necessary
        if(firstRowZero)
            for(int j=0; j<cols; j++)
                matrix[0][j] = 0;
        
//         Make first row zero if necessary
        if(firstColZero)
            for(int i=0; i<rows; i++)
                matrix[i][0] = 0;
        
    }
};
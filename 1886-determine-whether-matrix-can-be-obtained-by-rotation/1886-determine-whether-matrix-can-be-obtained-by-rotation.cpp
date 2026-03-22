class Solution {
private:
int n;

// To rotate a matrix clockwise, transpose then reverse rows
void rotateMatrix(vector<vector<int>>& mat) {
    // Transpose
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each row
    for(int i=0; i<n; i++)
        reverse(mat[i].begin(), mat[i].end());
}

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        // Rotate upto 4 times
        for(int r=1; r<=4; r++){
            bool isEqual = true;

            // Check for equal
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        isEqual = false;
                        break;
                    }
                }
                if(!isEqual)
                    break;
            }
            if(isEqual)
                return true;

            // Rotate if not equal
            rotateMatrix(mat);
        }
        return false;
    }
};
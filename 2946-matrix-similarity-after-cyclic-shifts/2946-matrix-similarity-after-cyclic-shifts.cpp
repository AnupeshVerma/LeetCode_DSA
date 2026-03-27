class Solution {
private:
    int rows, cols;
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        rows = mat.size();
        cols = mat[0].size();

        k %= cols;

        for(int row=0; row<rows; row++) {
            for(int col =0; col<cols; col++) {
                if(mat[row][col] != mat[row][(col + k)%cols])
                    return false;
            }
        }
        return true;
    }
};
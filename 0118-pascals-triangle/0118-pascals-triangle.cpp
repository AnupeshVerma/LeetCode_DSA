class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;

        // Initialize the triangle with all 1s
        for(int i=0; i<numRows; i++)
            pascal.push_back(vector<int>(i+1, 1));

        // Change the 1s after third row
        for(int i=2; i<numRows; i++) {
            for(int j=1; j<i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};
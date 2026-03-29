class Solution {
private:
    vector<vector<int>> name1(int numRows) {
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

    vector<vector<int>> name2(int numRows) {
        vector<vector<int>> pascal;

        for(int i=0; i<numRows; i++) {
            vector<int> row(i+1, 1);

            // Update the middle rows
            for(int j=1; j<i; j++) {
                row[j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
            pascal.push_back(row);
        }

        return pascal;
    }

public:
    vector<vector<int>> generate(int numRows) {
        
        return name2(numRows);
    }
};
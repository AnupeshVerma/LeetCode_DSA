class Solution {
private:
    long long bruteForce(vector<vector<int>>& points, int rows, int cols)
    {
        vector<long long>prev(cols);
        
        for(int col=0; col<cols; col++)
            prev[col] = points[0][col];
        
        for(int row=1; row<rows; row++)
        {
            vector<long long>curr(cols);
            for(int col=0; col<cols; col++)
            {
                for(int k=0; k<cols; k++)
                    curr[col] = max(curr[col], prev[k]+points[row][col]-abs(k-col));
            }
            prev = curr;
        }
        return *max_element(begin(prev), end(prev));
    }
    
    long long optimized(vector<vector<int>>& points, int rows, int cols)
    {
        vector<long long>prev(cols);
        for(int col=0; col<cols; col++)
            prev[col] = points[0][col];
        
        for(int row=1; row<rows; row++)
        {
            vector<long long>left(cols, 0);
            left[0] = prev[0];
            for(int col=1; col<cols; col++)
                left[col] = max(prev[col], left[col-1]-1);
            
            vector<long long>right(cols, 0);
            right[cols-1] = prev[cols-1];
            for(int col=cols-2; col>=0; col--)
                right[col] = max(prev[col], right[col+1]-1);
    
            vector<long long>curr(cols);
            for(int col=0; col<cols; col++)
                curr[col] = points[row][col] + max(left[col], right[col]);
            
            prev = curr;
        }
        return *max_element(begin(prev), end(prev));
    }
    
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        
        // return bruteForce(points, rows, cols);
        
           return optimized(points, rows, cols);

    }
};
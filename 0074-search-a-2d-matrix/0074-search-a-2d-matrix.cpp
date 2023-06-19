class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         Brute Force
        // for(auto i:matrix)
        //     for(auto j:i)
        //     {
        //         if(j==target)
        //             return true;
        //         if(j>target)
        //             return false;
        //     }
        // return false;
        
        
//         Optimal (Binary Search)
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = m*n-1;
        int mid = low + (high-low)/2;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            if(matrix[mid/m][mid%m] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
        
    }
};
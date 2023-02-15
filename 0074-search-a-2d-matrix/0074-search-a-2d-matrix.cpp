class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                if(j==target)
                    return true;
                if(j>target)
                    return false;
            }
        }
        return false;
    }
};
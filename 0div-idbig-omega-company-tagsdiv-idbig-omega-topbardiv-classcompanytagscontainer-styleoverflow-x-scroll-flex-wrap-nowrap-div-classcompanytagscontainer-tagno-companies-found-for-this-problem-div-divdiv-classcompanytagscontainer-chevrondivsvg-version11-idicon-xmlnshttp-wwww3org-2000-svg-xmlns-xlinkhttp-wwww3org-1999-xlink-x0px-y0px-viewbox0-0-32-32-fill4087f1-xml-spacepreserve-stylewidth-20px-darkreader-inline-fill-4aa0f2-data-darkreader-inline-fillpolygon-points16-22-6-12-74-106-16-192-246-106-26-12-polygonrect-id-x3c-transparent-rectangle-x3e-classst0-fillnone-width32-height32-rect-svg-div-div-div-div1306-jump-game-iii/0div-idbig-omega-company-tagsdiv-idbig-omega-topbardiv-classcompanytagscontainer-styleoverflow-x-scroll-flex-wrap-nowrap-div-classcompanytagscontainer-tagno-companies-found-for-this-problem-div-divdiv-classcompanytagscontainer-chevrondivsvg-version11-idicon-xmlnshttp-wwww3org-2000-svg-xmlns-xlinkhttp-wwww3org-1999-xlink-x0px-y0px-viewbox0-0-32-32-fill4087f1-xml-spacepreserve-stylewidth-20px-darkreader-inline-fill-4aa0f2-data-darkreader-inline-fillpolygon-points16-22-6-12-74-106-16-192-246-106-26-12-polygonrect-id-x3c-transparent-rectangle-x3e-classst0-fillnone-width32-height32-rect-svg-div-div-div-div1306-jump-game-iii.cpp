class Solution {
public:
    bool reach(vector<int>&arr, int start, int n, vector<int>& visited)
    {
        if(start<0 || start>n-1)
            return false;
        if(visited[start] ==1)
            return false;
        
        if(arr[start] == 0)
            return true;
        
        visited[start] = 1;

        bool forward = reach(arr, start+arr[start], n, visited);
        bool backward= reach(arr, start-arr[start], n, visited);
        
        return forward || backward;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n, 0);
        return reach(arr, start, n, visited);
    }
};
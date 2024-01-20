class Solution {
public:
//     ---------> Recursion <-------
    bool reach(vector<int>&arr, int start, int n, vector<int>& visited)
    {
        if(start<0 || start>n-1)
            return false;
        if(visited[start] == 1)
            return false;
        
        if(arr[start] == 0)
            return true;
        
        visited[start] = 1;

        bool forward = reach(arr, start+arr[start], n, visited);
        bool backward= reach(arr, start-arr[start], n, visited);
        
        return forward || backward;
    }
    
//     -------------------> Using Queue <-------------
    bool usingQueue(vector<int>& arr, int start)
    {
        int n = arr.size();
        queue<int>q;
        vector<int> visited(n, 0);
        
        q.push(start);
        while(!q.empty())
        {
            int currPosition = q.front();
            q.pop();
            
            if(arr[currPosition] == 0)
                return true;
            
            if(!visited[currPosition])
            {
                visited[currPosition] = 1;
                if(currPosition - arr[currPosition] >= 0)
                    q.push(currPosition-arr[currPosition]);
                
                if(currPosition + arr[currPosition] <= n-1)
                    q.push(currPosition + arr[currPosition]);
            }
            
        }
        return false;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n, 0);
        // return reach(arr, start, n, visited);
        
        
        return usingQueue(arr, start);
    }
};
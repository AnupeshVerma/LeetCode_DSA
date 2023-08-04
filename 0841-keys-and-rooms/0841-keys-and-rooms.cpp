class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto adjNode : rooms[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        for(int i : visited)
            if(i==0)
                return false;
        return true;
    }
};
class Solution {

    void dfs(vector<int>adj[], vector<int>&visited, int node)
    {
        visited[node] = 1;
        
        for(auto adjNode : adj[node])
        {
                if(!visited[adjNode])
                    dfs(adj, visited, adjNode);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces = 0;
        vector<int>adj[n];
        
        vector<int>visited(n, 0);
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if( isConnected[i][j] == 1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(adj, visited, i);
            }
        }
            
        return provinces;
    }
};
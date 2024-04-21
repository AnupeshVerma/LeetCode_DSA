class Solution {
    private:
    bool dfs(int source, int dest, vector<int>adj[], vector<int>&visited)
    {
        visited[source] = 1;
        if(source == dest)
           return true;
        
        for(auto adjNode: adj[source])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, dest, adj, visited))
                    return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>adj[n];
        vector<int>visited(n,0);
        
        for(int i=0; i<edges.size(); i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        return dfs(source, destination, adj, visited);
    }
};
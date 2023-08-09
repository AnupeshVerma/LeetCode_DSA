class Solution {
private:
    bool dfs(vector<vector<int>>&adj, vector<int>&visited, vector<int>&path_visited, vector<int>&safe, int node)
    {
        visited[node] = 1;
        path_visited[node] = 1;
        
        for(auto adjNode : adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adj, visited, path_visited, safe, adjNode))
                    return true;
            }
            else if(path_visited[adjNode])
                return true;
        }
        safe.push_back(node);
        path_visited[node] = 0;
        return false;
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>visited(n, 0), path_visited(n, 0);
        vector<int>safe;
        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(graph, visited, path_visited, safe, i);
        sort(safe.begin(), safe.end());
        return safe;
    }
};
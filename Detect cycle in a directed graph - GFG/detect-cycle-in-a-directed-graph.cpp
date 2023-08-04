//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int v, vector<int>adj[], int visited[], int pathVisited[], int node)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        // Check for adjancent nodes
        for(auto adjNode:adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(v, adj, visited, pathVisited, adjNode))
                    return true;
            }
            else if(pathVisited[adjNode])
                return true;
        }
        pathVisited[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int visited[V] = {0};
        int pathVisited[V] = {0};
        
        // Check for all components
        for(int i=0; i<V; i++)
            if(!visited[i])
                if(dfs(V, adj, visited, pathVisited, i))
                    return true;
                    
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
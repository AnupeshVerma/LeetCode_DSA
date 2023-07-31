//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool cycleBFS(int src, vector<int>adj[], vector<int>&visited)
    {   
        // queue<pair<node,parent>>q;
        queue<pair<int,int>>q;
        q.push({src, -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode:adj[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push({adjNode, node});
                }
                // If the node is visited and not its parent then it means
                // someone else already visit that node before
                // Parent node hamesha hi visited hoga usi se to hoke aaye h
                else if(parent != adjNode)
                    return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int>visited(v, 0);
        
        // For multiple components
        for(int i=0; i<v; i++)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                if(cycleBFS(i, adj, visited))
                    return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
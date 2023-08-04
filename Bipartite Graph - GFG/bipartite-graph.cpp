//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int v, vector<int>adj[], int visited[], int node, int color[])
    {
        visited[node] = 1;
        for(auto adjNode : adj[node])
        {
            if(!visited[adjNode])
            {
                color[adjNode] = !color[node];
                if(!check(v, adj, visited, adjNode, color))
                    return false;
            }
            else if(color[adjNode] == color[node])
                return false;
        }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    int visited[v] = {0};
	    int color[v] = {0};
	    
	    for(int i=0; i<v; i++)
	    {
	       if(!visited[i])
            {
                color[i] = 0;  // set initial color for the starting node
                if(check(v,adj,visited, i, color) == false)
                    return false;
            }
	    }
	    return  true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
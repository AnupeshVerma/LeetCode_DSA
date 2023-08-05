//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  void topoSort(vector<pair<int,int>>adj[], stack<int>&st, int visited[], int node)
  {
      visited[node] = 1;
      for(auto it : adj[node])
      {
          int adjNode = it.first;
          if(!visited[adjNode])
            topoSort(adj, st, visited, adjNode);
      }
      st.push(node);
  }
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(auto it: edges)
            adj[it[0]].push_back({it[1],it[2]});
        
        stack<int>st;
        int visited[N] = {0};
        topoSort(adj, st, visited, 0);
        
        vector<int>distance(N, INT_MAX);
        distance[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int dist = it.second;
                
                distance[adjNode] = min(distance[adjNode], distance[node] + dist);
                
            }
        }

        for(int i=0; i<N; i++)
            if(distance[i] == INT_MAX)
                distance[i] = -1;
                
        return distance;
         
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
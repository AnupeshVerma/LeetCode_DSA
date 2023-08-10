class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>>adj[n];
        
        for(auto it:redEdges)
            adj[it[0]].push_back({it[1], 0});
        for(auto it:blueEdges)
            adj[it[0]].push_back({it[1], 1});
        
// To ensure one node should not visited again with same color, take set storing {node,color}
        vector<int> dist(n, 1e8);
        set<pair<int, int>>visited;   
        queue<pair<int, pair<int,int>>>q;
        
        dist[0] = 0;    // Distance of node zero = 0
        visited.insert({0, 0}); // Mark visited node 0 with red color
        visited.insert({0, 1}); // Mark visited node 0 with blue color
        q.push({0, {0, -1}});
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int node = q.front().second.first;
            int color = q.front().second.second;
            q.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int adjColor= it.second;
                if(visited.find({adjNode, adjColor})==visited.end() && color != adjColor)
                {
                    if(dis+1 <= dist[adjNode])
                        dist[adjNode] = dis+1;
                    visited.insert({adjNode, adjColor});
                    q.push({dis+1, {adjNode, adjColor}});
                }
            }
        }
        for(int i=0; i<n; i++)
            if(dist[i] == 1e8)
                dist[i] = -1;
        return dist;
                
    }
};
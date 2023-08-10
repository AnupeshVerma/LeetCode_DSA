class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>>adj[n];
        
        for(auto it:redEdges)
            adj[it[0]].push_back({it[1], 0});
        for(auto it:blueEdges)
            adj[it[0]].push_back({it[1], 1});
        
        vector<int> dist(n, 1e8);
        set<pair<int, int>>visited;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        dist[0] = 0;    // Distance of node zero = 0
        visited.insert({0, 0}); // Mark visited node 0 with red color
        visited.insert({0, 1}); // Mark visited node 0 with blue color
        pq.push({0, {0, -1}});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int color = pq.top().second.second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int adjColor= it.second;
                if(visited.find({adjNode, adjColor})==visited.end() && color != adjColor)
                {
                    if(dis+1 <= dist[adjNode])
                        dist[adjNode] = dis+1;
                    visited.insert({adjNode, adjColor});
                    pq.push({dis+1, {adjNode, adjColor}});
                }
            }
        }
        for(int i=0; i<n; i++)
            if(dist[i] == 1e8)
                dist[i] = -1;
        return dist;
                
    }
};
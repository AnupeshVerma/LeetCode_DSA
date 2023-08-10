class Solution {
public:
    int methodOne(int n, vector<vector<int>>& connections)
    {
        vector<int>adj[n];
        set<vector<int>>st;
        
        for(auto i:connections)
        {
            st.insert(i);
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n, 0);
        queue<int>q;
        
        q.push(0);
        visited[0] = 1;

        
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int adjNode:adj[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                    if(st.find({adjNode, node}) == st.end())
                        count++;
                }
            }
        }
        return count;
    }
    
    int methodTwo(int n, vector<vector<int>>connections)
    {
        vector<pair<int, int>>adj[n];
        for(auto i:connections)
        {
            adj[i[0]].push_back({i[1], 1});
            adj[i[1]].push_back({i[0], 0});
        }
        
        vector<int>visited(n, 0);
        queue<int>q;
        
        visited[0]=1;
        q.push(0);
        
        int ans = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
           
            for(auto [adjNode, adjwt] : adj[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                    ans+=adjwt;
                }
            }
            
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
//        Using set to store original edges
        // return methodOne(n, connections);
        
//         Assigning weights to backward and forward edges
        return methodTwo(n, connections);
    }
};
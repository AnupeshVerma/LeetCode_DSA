class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
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
};
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int, int>>adj[n];
        for(int i=0; i<n; i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back({i, informTime[manager[i]]});
            
//     Using Djikstra's Algorithm
        vector<int>time(n, 1e8);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, headID});
        time[headID] = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int timeTill = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int adjTime = it.second;
                
                if(timeTill + adjTime < time[adjNode])
                {
                    time[adjNode] = timeTill + adjTime;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }
        
        int maxTime = 0;
        for(auto i:time)
            maxTime = max(maxTime, i);
        
        return maxTime;
                                           
    }
};
class Solution {
private:
    bool isConnection(int src, int target, vector<int>adjList[], vector<bool>& visited) {
        
        visited[src] = true;
        
        if(src == target)
            return true;
        
        bool isFound = false;
        for(auto adj : adjList[src]) {
            if(!visited[adj])
                isFound = isFound || isConnection(adj, target, adjList, visited);
        }
        return isFound;
    }


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adjList[n+1];

        for(auto edge : edges) {
            vector<bool> visited(n+1, false);
            if(isConnection(edge[0], edge[1], adjList, visited)) 
                return edge;

            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return {};
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    vector<int>temp;
    
    void dfs(int node, vector<vector<int>>&graph, vector<int>visited)
    {
        if(node == graph.size()-1)
        {
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        visited[node]=1;
        temp.push_back(node);
        for(auto adjNode:graph[node])
            if(!visited[adjNode])
            {
                dfs(adjNode, graph, visited);
            }
        temp.pop_back();
        visited[node] = 0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, 0);
        
        dfs(0, graph, visited);
        return ans;
    }
};
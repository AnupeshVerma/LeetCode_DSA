class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(edges.size() == 0){
            ans.push_back(0);
            return ans;
        }
        unordered_map<int,list<int>>graph;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int>leafs;
        for(auto it : graph){
            if(it.second.size() == 1){
                leafs.push_back(it.first);
            }
        }

        while(n>2){
            vector<int>new_leafs;
            n-=leafs.size();
            for(auto it : leafs){
                int child = graph[it].front();
                graph[child].remove(it);
                if(graph[child].size() == 1){
                    new_leafs.push_back(child);
                }
            }
            leafs=new_leafs;
        }

        return leafs;
    }
};
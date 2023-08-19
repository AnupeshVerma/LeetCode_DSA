class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
//         Method 1 (More Efficient as set takes O(1) in searching)
//         vector<int>degree(n, 0);
//         set<pair<int, int>>st;
//         for(auto it:roads)
//         {
//             st.insert({it[0], it[1]});
//             st.insert({it[1], it[0]});
//             degree[it[0]]++;
//             degree[it[1]]++;
//         }
        
//         int ans = INT_MIN;
//         for(int i=0; i<n; i++)
//             for(int j=i+1; j<n; j++)
//             {
//                 int sum_degree = degree[i] + degree[j];
//                 if(st.find({i, j}) != st.end())
//                     ans = max(ans, sum_degree-1);
//                 else
//                     ans = max(ans, sum_degree);
//             }
//         return ans;
        
        
//         Method 2
        vector<int>adj[n];
        
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                int rank = adj[i].size() + adj[j].size();
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end())
                    rank--;
                ans = max(rank, ans);
            }
        return ans;
    }
};
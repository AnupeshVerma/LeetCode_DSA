class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n, 0);
        
        set<pair<int, int>>st;
        
        
        for(auto it:roads)
        {
            st.insert({it[0], it[1]});
            st.insert({it[1], it[0]});
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                int sum_degree = degree[i] + degree[j];
                if(st.find({i, j}) != st.end())
                    ans = max(ans, sum_degree-1);
                else
                    ans = max(ans, sum_degree);
            }
        return ans;
    }
};
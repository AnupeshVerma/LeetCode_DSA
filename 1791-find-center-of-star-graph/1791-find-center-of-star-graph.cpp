class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
//         int n = edges.size();
//         unordered_map<int,int>mp;
        
//         for(auto i:edges)
//             for(auto j:i)
//             {
//                 mp[j]++;
//             }
//         int ans, freq=0;
//         for(auto it:mp)
//         {
//             cout<<it.second;
//             if(it.second > freq)
//             {
//                 ans = it.first;
//                 freq = it.second;
//             }
//         }
//         return ans;
        
//         Since n-1 nodes are connected to center, there will be no other nodes connected
//         We compare first four only
//         Phle vectorke dono me se hi ek center hoga
//         Dono me konsa node dusre vector me present h whi center h
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};
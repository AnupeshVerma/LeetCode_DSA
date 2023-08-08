class Solution {
    public:
int rec(vector<vector<int>>&m, int i, int p,vector<vector<int>>&d){
        if(i>=m.size())return 0;
        if(d[i][p]!=-1) return d[i][p];
        int ans;
        if(p<=m[i][1]) ans=max(rec(m,i+1,p,d),m[i][0]+rec(m,i+1,m[i][1],d));
        else ans=rec(m,i+1,p,d);
        return d[i][p]=ans;
    }
    int bestTeamScore(vector<int>&s, vector<int>&a) {
        vector<vector<int>>m;
        for(int i=0;i<s.size();i++){
            m.push_back({s[i],a[i]});
        }
        vector<vector<int>>d(s.size()+1,vector<int>(1001,-1));
        sort(m.begin(),m.end());
        return rec(m,0,0,d);
    }
};
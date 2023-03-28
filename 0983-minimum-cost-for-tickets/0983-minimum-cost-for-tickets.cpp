class Solution {
public:
    int f(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
        if(i>=days.size())return 0;

        if(dp[i]!=-1)return dp[i];
        int op1=costs[0]+f(days,costs,i+1,dp);
        int j;
        for(j=i;j<days.size() && days[i]+7>days[j];j++);
        int op2=costs[1]+f(days,costs,j,dp);
        for(j=i;j<days.size() && days[i]+30>days[j];j++);
        int op3=costs[2]+f(days,costs,j,dp);

        return dp[i]=min({op1,op2,op3});
          
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);

        
        return f(days,costs,0,dp);

        
    }
};
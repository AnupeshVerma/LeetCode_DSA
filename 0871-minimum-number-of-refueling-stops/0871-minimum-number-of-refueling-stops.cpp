class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

//         We need an array to store the maximum distance that can be travelled with i stops
//         With refueling zero times, we can go upto startFuel miles
//         Maximum refueling we can do equal to the no. of stations given to us
        
        int n = stations.size();
        vector<long>dp(n+1, 0);
        dp[0] = startFuel;
        
//         At each of the station we have to determine the maximum distance that we can cover if    we use this station as a refueling station
//         We know that there will be stations before this particular station & each previous station can be a refueling station
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j>=0; j--)
            {
                // If we are using this station are refueling, refill counter should increment 1
                // Distance covered with j refuelings should be more or equal to position of current station otherwise it will not reach the current station
               // value will be max of this place and Value present at previous station plus fuel at this station
                if(dp[j] >= stations[i][0])
                    dp[j+1] = max(dp[j+1], dp[j]+stations[i][1]);
            }
        }
        
//         Now we have to find the first index where we have crossed the target
        for(int i=0; i<=n; i++)
            if(dp[i] >= target)
                return i;
        
        return -1;
    }
};
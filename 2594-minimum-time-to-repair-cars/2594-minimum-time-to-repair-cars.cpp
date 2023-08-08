class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        
        sort(ranks.begin(), ranks.end());
        long long minTime = ranks[0];
        long long maxTime = 1L*ranks[n-1]*cars*cars;
        
        while(minTime < maxTime)
        {
            long long midTime = minTime + (maxTime-minTime)/2;
            long long carCount = 0;
            for(int i=0; i<n; i++)
            {
                /*
                time = rank*car*car
                car*car = time/rank
                car = sqrt(time/rank)
                */
               carCount += sqrt(midTime/ranks[i]);
               
            }
           
            if(carCount >= cars)
                maxTime = midTime;
            else
                minTime = midTime+1;
        }
        return minTime;
    }
};
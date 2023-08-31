class Solution {
// private:
//     int solve(int n, vector<pair<int, int>>vec, int ind)
//     {
        
//         for(int i=ind; i<vec[ind].second; i++)
//         {
//             maxRight = max()
//         }
//     }
public:
     static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>>vec;
       
        for(int i=0; i<=n; i++)
        {
            int leftRange  = i-ranges[i]>0 ? i-ranges[i] : 0;
            int rightRange = i+ranges[i];
            vec.push_back({leftRange, rightRange});
        }
        
        sort(vec.begin(), vec.end(),cmp);
        
        int curRight = vec[0].second;
        int maxRight = vec[0].second;
        int count=1, i=0;
        
        while(curRight < n)
        {
            count++;
            while(i<=n && vec[i].first<=curRight)
            {
                maxRight = max(vec[i].second, maxRight);
                i++;
            }
            if(maxRight > curRight)
                curRight = maxRight;
            else
                break;
            
        }
        return curRight<n ? -1 : count;
    }
};
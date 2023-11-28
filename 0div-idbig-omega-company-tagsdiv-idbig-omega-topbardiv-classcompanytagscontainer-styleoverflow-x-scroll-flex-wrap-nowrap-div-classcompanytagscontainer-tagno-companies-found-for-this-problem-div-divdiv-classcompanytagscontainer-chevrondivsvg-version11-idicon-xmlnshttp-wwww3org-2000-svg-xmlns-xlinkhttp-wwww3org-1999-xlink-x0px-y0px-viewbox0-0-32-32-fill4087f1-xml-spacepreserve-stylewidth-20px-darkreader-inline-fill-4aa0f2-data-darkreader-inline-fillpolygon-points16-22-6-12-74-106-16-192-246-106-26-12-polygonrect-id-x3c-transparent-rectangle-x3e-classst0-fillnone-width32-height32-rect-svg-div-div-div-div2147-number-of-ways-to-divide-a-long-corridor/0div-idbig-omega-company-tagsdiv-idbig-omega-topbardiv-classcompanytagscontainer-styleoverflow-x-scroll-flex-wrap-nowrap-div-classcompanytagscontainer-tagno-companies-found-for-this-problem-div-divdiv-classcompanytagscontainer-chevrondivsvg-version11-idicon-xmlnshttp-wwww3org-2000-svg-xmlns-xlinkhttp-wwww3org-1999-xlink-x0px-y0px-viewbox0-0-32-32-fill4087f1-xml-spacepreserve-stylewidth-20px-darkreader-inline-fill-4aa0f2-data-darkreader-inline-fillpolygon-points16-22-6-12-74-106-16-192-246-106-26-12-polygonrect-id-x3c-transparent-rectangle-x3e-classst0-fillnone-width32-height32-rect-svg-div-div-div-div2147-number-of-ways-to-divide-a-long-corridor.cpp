class Solution {
    int mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        long long ans = 1;
        vector<int>arr;
        
        for(int i=0; i<n; i++)
            if(corridor[i] == 'S')
                arr.push_back(i);
        
        if(arr.size()%2 != 0 || arr.size() == 0)
            return 0;
        
        for(int i=2; i<arr.size(); i+=2)
        {
            ans *= (arr[i] - arr[i-1]);
            ans %= mod;
        }
        return ans;    
    }
};
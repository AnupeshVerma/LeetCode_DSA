class Solution {
public:
    int mySqrt(int x) {
        
        int ans = 1;
        
        while((long long int)ans*ans <= x)
            ans++;
        
        return ans-1;
    }
};
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        
        int weeks = n/7;
        int remDays = n%7;
        
        for(int i=0; i<weeks; i++)
        {
            ans += (7+i)*(7+i+1)/2 - i*(i+1)/2;
            
        }
        
        ans += (remDays+weeks)*(remDays+weeks+1)/2 - (weeks)*(weeks+1)/2;
        return ans;
    }
};
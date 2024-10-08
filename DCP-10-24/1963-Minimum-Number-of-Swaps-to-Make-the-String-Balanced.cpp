class Solution {
private:
    int usingStack(string s){
        int ans = 0;
        
        for(char c : s){
            if(c == '[')
               ans ++;
            else
                ans > 0 ? ans-- : ans=0;
        }
        return (ans+1)/2;
    }
public:
    int minSwaps(string s) {
        
        return usingStack(s);
    }
};
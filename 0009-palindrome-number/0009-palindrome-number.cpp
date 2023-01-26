class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0;
        int copyx = x;
        
        while(x>0)
        {
            rev = rev*10 + x%10;
            x/=10;
        }
        cout<<rev;
         return copyx==rev;
    }
};
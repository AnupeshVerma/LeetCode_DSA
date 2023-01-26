class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        
        while(x)
        {
             if (rev > 214748364 || (rev == 214748364 && x%10 > 7)) 
                return 0;
            
            if (rev < -214748364 || (rev == -214748364 && x%10 == -9))
                return 0;
            rev = rev*10 + x%10;
            x/=10;
        }
         return rev;
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
       long long int val = 1;
        while(val <= n)
        {
            if(val == n)
                return true;
            val*=3;
        }
        return false;  
    }
};
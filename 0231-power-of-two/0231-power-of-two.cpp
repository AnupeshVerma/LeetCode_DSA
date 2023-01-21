class Solution {
public:
    long long int val = 1;
    bool isPowerOfTwo(int n) {
        if(val>n)
            return false;
        if(val == n)
            return true;
        
        val*=2;
        return isPowerOfTwo(n);
    }
};
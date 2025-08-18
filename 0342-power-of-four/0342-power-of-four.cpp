class Solution {
private:
    bool division(int n) {
    while(n % 4 == 0)
        n /= 4;
    
    return n==1;
    }



public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
            
        return division(n);    
    }
};
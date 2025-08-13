class Solution {
private:
    bool bruteForce(int n) {
        for(int i=0; i<n; i++){
            long powerVal = pow(3, i);
            if(powerVal > n)
                return false;
            if(powerVal == n)
                return true;
        }
        return false;
    }
public:
    bool isPowerOfThree(int n) {
        return bruteForce(n);
    }
};
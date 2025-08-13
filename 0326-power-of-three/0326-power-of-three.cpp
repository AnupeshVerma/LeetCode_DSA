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

    bool simplest(int n) {
        int maxPowerOfThree = 1162261467; // 3^19 is the largest power of 3 in int range
        return n > 0 && maxPowerOfThree % n == 0;
    }

public:
    bool isPowerOfThree(int n) {

        // return bruteForce(n);

        return simplest(n);
    }
};
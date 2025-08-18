class Solution {
private:
    bool division(int n) {
    while(n % 4 == 0)
        n /= 4;
    
    return n==1;
    }

    bool bitManipulation(int n) {
        // 4  -> 100
        // 16 -> 10000
        // 64 -> 1000000
        //  => single 1 & always at odd place

        // Check if it is a power of two
        bool powerOfTwo = (n & (n-1)) == 0;

        // Check for the position of the set bit, should be at odd position
        // 0x55555555 -> 01010101010101010101010101010101
        bool setBitAtOddPlace = n & 0x55555555;
        // return powerOfTwo && setBitAtOddPlace;

                    // OR 

        // 0xAAAAAAAA -> 10101010101010101010101010101010
        bool setBitAtEvenPlace = n & 0xAAAAAAAA;
        return powerOfTwo && !setBitAtEvenPlace;

    }

public:
    bool isPowerOfFour(int n) {
        // Check for the number, should be positive
        if(n <= 0)
            return false;

        return bitManipulation(n);

        return division(n);    
    }
};
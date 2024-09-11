class Solution {
private:
    int bruteForce(int start, int goal)
    {
        int flips = 0;
        while(start || goal)
        {
            if((start & 1) != (goal & 1))
                flips ++;
            start = start >> 1;
            goal = goal >> 1;
        }
        return flips;
    }
    
public:
    int minBitFlips(int start, int goal) {
        
        return bruteForce(start, goal);
    }
};
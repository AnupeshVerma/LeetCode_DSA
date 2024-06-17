class Solution {
private:
    bool bruteForce(int c)
    {
        for(int i=0; i<=sqrt(c); i++){
            for(int j=0; j<=sqrt(c); j++){
                int temp = i*i + j*j;
                if(temp == c)
                    return true;
            }
        }
        return false;
    }
    
    bool oneLoop(int c)
    {
        for(int i=0; i<=sqrt(c); i++){
            int b2 = c - i*i ;
            int b = sqrt(b2);
            if(b*b == b2)
                return true;
            
        }
        return false;
    }
    
    
public:
    bool judgeSquareSum(int c) {
        
        // return bruteForce(c);
        
        return oneLoop(c);
    }
};
class Solution {
private:
    int twoPointer(vector<int>& tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        
        int n = tokens.size(), score=0;
        int front=0, back=n-1;
        
        while(front<=back)
        {
            if(tokens[front] <= power)
            {
                score++;
                power -= tokens[front];
                front++;
                continue;
            }
            if(score >= 1 && front != back)
            {
                score--;
                power += tokens[back];
                back--;
            }
            else
                break;
        } 
        return score;
    }
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        return twoPointer(tokens, power);
    }
};
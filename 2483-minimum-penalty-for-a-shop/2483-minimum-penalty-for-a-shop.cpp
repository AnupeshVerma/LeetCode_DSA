class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int score=0, maxScore = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            customers[i]=='Y' ? score++ : score--;
            if(score > maxScore)
            {
                maxScore = score;
                ans = i+1;
            }
        }
        return ans;
        
    }
};
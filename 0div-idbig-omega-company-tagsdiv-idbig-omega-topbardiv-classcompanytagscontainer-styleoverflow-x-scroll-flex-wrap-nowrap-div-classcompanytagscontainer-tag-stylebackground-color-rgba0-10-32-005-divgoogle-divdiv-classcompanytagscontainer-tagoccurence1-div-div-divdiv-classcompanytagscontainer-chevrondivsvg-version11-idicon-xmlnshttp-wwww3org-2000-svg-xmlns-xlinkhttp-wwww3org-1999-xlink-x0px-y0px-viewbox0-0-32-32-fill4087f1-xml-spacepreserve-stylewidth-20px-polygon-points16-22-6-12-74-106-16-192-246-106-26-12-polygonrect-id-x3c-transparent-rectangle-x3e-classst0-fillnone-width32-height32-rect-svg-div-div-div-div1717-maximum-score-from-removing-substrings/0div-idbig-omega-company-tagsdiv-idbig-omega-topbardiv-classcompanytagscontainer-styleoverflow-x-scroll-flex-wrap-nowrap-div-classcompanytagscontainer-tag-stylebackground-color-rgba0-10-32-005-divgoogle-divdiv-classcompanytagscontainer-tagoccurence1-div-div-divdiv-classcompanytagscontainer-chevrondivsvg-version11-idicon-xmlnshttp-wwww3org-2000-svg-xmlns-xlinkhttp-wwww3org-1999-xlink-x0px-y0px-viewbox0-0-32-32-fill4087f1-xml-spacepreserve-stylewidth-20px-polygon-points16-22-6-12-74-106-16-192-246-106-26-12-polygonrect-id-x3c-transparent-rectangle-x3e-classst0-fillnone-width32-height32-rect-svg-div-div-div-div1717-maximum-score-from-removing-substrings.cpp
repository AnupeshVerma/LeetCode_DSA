class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        
        if(x > y)
        {
            // First remove "ab" then "ba" --> 'ab' has high priority
            totalScore += removeSubstring(s, "ab", x);
            totalScore += removeSubstring(s, "ba", y);

        }
        else
        {
            // First remove "ba" then "ab" --> 'ba' has high priority
            totalScore += removeSubstring(s, "ba", y);
            totalScore += removeSubstring(s, "ab", x);

        }
        return totalScore;
    }
    
    int removeSubstring(string& s, string toRemove, int points)
    {
        int score = 0;
        string sAfterRemoval = "";
        
        for(int i=0; i<s.size(); i++)
        {
            sAfterRemoval += s[i];
            int size  = sAfterRemoval.size();
            if(size>1 && sAfterRemoval[size-2]==toRemove[0] && sAfterRemoval[size-1]==toRemove[1])
            {
                sAfterRemoval.erase(sAfterRemoval.end()-2, sAfterRemoval.end());
                score += points;
                
            }
        }
        s = sAfterRemoval;
        return score;
    }
};
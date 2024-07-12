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
        int j = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            s[j++] = s[i];
            if(j>1 && s[j-2]==toRemove[0] && s[j-1]==toRemove[1])
            {
                j -= 2;
                score += points;
            }
        }
         s.erase(s.begin() + j, s.end());
        return score;
    }
};
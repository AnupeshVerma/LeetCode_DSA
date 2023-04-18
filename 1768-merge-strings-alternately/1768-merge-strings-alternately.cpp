class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n1 = word1.size(), n2 = word2.size();
        int ind = 0;
        
        while(ind < min(n1, n2))
        {
            ans += word1[ind], ans += word2[ind], ind++;
        }
        
        while(ind < n1)
            ans += word1[ind++];
        while(ind < n2)
            ans += word2[ind++];
        
        return ans;
            
    }
};
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;

        int n = s1.size();
        int s1freq[26] = {0};
        int s2freq[26] = {0};
        int diffCount = 0;
        for(int i=0; i<n; i++) {
            if(s1[i] != s2[i])
                diffCount++;
            if(diffCount > 2)
                return false;
            
            s1freq[s1[i] - 'a']++;
            s2freq[s2[i] - 'a']++;
        }

        for(int i=0; i<26; i++)
            if(s1freq[i] != s2freq[i])
                return false;

        return true;
    }
};
class Solution {
public:
   bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> mp;
        
        for(int i=0; i<n; i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            if(mp.find(c1) != mp.end())
            {
                if(mp[c1] != c2)
                    return 0;
                
            }
            else
            {
                for (int j=0; j<i; j++) 
                    if(mp[s[j]] == t[i])
                        return 0;
                mp[c1] = c2;
            }
        }
        return 1;
    }
};
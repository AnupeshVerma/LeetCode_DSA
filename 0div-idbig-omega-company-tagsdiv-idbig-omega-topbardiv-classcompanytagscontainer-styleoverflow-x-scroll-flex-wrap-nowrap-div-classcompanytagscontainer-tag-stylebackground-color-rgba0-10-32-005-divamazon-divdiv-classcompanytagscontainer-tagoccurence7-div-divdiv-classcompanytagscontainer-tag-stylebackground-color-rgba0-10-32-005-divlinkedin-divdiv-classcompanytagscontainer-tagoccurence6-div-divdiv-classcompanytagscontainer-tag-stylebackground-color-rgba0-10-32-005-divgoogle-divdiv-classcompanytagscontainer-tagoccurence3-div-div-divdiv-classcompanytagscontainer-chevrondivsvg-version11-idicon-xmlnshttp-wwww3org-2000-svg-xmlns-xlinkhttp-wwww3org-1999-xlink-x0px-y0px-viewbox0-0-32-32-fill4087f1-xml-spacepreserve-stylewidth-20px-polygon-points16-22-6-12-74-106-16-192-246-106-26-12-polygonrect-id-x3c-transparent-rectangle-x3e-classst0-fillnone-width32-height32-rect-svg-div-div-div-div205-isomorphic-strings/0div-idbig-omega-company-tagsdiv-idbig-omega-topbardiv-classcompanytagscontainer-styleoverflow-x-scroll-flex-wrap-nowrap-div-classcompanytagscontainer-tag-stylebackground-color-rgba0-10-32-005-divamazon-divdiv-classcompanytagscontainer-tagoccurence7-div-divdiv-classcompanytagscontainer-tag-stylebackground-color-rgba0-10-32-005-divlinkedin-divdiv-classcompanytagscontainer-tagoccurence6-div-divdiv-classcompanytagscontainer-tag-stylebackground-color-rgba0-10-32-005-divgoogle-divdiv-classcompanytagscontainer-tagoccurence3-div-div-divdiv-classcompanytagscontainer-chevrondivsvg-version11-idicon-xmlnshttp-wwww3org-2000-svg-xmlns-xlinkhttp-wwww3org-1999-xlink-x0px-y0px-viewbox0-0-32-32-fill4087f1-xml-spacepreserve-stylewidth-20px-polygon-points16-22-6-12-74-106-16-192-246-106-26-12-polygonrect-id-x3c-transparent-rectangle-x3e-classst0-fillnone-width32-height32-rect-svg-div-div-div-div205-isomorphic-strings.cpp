class Solution {
public:
   bool isIsomorphic(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();

        if(len1 != len2){
            return 0;
        }
        int i = 0;
        map<char,char> mp;
        while(i < len1){
            char c1 = s[i];
            char c2 = t[i];
            if(mp.find(c1) != mp.end()){
                char c3 = mp[c1];
                if(c3 != c2){
                    return 0;
                }
            }else{
            //mp[c1] = c2;
                for (int j = 0; j < i; j++) {
                    char c3 = mp[s[j]];
                    if(c3 == t[i]){
                        return 0;
                    }
                
                }
                mp[c1] = c2;
                
            }
            i++;
        }
        return 1;
    }
};
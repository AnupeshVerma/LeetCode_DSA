class Solution {
private:
    int mod = 1e9 + 7;
    int charMapping(string s, int t, int n) {
        vector<int> count(26, 0);

        for(char c : s)
            count[c - 'a']++;

        while(t--) {
            vector<int>temp_count(26, 0);
            temp_count[0] = count[25];
            temp_count[1] = (count[25] + count[0]) % mod;
            for(int i=2; i<26; i++)
                temp_count[i] = count[i -1];
        }

        int ans = 0;
        for(int i=0; i<26; i++)
            ans += count[i] % mod;
        
        return ans % mod;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        
        return charMapping(s, t, n);

        // for(int i=0; i<t; i++) {
        //     if(s[i] - 'z' <= t)
        //         n++;
        // }
        // return n;
    }
};
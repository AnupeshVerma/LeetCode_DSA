class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int k = pref.size();
        int count = 0;
        
        for(string word : words) {
            string subs = word.substr(0, k);
            if(subs == pref)
                count++;
        }
        return count;
    }
};
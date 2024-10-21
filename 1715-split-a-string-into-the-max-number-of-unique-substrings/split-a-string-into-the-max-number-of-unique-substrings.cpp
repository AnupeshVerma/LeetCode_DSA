class Solution {
private:
    int backtrack(string s, int i, unordered_set<string>& st) {
        if(i == s.size())
            return 0;
         
         int max_splits = 0;
         for(int j=i; j<s.size(); j++) {
            string substring = s.substr(i, j-i+1);
            if(st.find(substring) == st.end()) {
                st.insert(substring);
                max_splits =  max(max_splits, 1 + backtrack(s, j+1, st));
                st.erase(substring);
            }
         }
         return max_splits;
    }


public:
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        return backtrack(s, 0, st);
    }
};
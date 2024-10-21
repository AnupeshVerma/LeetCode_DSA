class Solution {
private:
    int bruteForce(string s, int n) {
        unordered_set<string> st;
        string temp = "";
        for(int i=0; i<n; i++){
            temp += s[i];
            if(st.find(temp) == st.end()) {
                cout<<temp<<" ";
                st.insert(temp);
                temp = "";
            }
        }
        return st.size();
    }


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
        int n = s.size();

        // return bruteForce(s, n);

        unordered_set<string>st;
        return backtrack(s, 0, st);
    }
};
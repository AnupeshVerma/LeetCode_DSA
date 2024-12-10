class Solution {
private:
    bool isSpecial(string s) {
        char a = s[0];
        for(char c : s)
            if(c != a)
                return false;
        return true;
    }


    int bruteForce(string s, int n) {
        unordered_map<string, int> freq;

        for(int i=0; i<n; i++) {
            string temp = "";
            for(int j=i; j<n; j++) {
                temp += s[j];
                if(isSpecial(temp))
                    freq[temp]++;
            }
        }

        int ans = -1;
        for(auto it : freq){
            if(it.second >= 3) {
                cout<<it.first<<" "<<it.second<<" | ";
                int size = it.first.size();
                ans = max(ans, size);
            }
        }
        return ans;
    }
public:
    int maximumLength(string s) {
        int n = s.size();

        return bruteForce(s, n);
    }
};
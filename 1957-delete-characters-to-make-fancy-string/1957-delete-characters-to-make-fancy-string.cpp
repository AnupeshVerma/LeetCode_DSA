class Solution {
private:
    string bruteForce(string s) {
        string ans = "";
        int count = 1;

        ans += s[0];
        for(int i=1; i<s.size(); i++) {
            s[i] == s[i-1] ? count++ : count = 1;

            if(count < 3)
                ans += s[i];
        }
        return ans;
    }
public:
    string makeFancyString(string s) {

        return bruteForce(s);      
    }
};
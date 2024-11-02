class Solution {
private:
    bool bruteForce(string s, int n) {
        if(s[0] != s[n-1])
            return 0;

        for(int i=0; i<n; i++) {
            if(s[i] == ' ' and s[i-1] != s[i+1])
                return false;
        }
        return true;
    }
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        return bruteForce(sentence, n);
              
    }
};
class Solution {
private:
    string bruteForce(string word, int n) {
        string comp = "";
        
        int count = 0;
        for(int i=0; i<n-1; i++) {
            count++;
            if (count == 9 || word[i] != word[i+1]) {
                comp += to_string(count) + word[i];
                count = 0;
            }
        }
        comp += to_string(count+1) + word[n-1];
        return comp;
    }
    
    
public:
    string compressedString(string word) {
        int n = word.size();
        
        return bruteForce(word, n);
    }
};
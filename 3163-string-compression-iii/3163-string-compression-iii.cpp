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
    
    
    string manipulation(string word, int n) {
        string comp = "";
        int i = 0;
        
        while(i < n) {
            int count = 0;
            char curr = word[i];
            
            while(i<n && curr==word[i] && count<9) {
                count++;
                i++;
            }
            comp += to_string(count) + curr;
        }
        return comp;
    }
    
    
public:
    string compressedString(string word) {
        int n = word.size();
        
        // return bruteForce(word, n);
        
        return manipulation(word, n);
    }
};
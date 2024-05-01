class Solution {
private:
    string bruteForce(string word, char ch, int n)
    {
        int ind=0;
       for(int i=0; i<n; i++)  
       {
           if(word[i] == ch) 
           {
               ind = i;
               break;
           }
       }
        
        reverse(word.begin(), word.begin()+ind+1);
        
        return word;
    }
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        return bruteForce(word, ch, n);
    }
};
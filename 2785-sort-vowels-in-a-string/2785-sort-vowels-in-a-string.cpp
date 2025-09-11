class Solution {
private:
    string storeAndFill(string s, int n) {
        vector<char> vowels;

        // Store the vowels
        for(char c : s){
            char lc = tolower(c);
            if(lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                vowels.push_back(c);
        }

        // Fill again after sorting
        sort(vowels.begin(), vowels.end());
        int i = 0;
        for(char& c : s){
            char lc = tolower(c);
            if(lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                c = vowels[i++];
        }
        return s;
    }


public:
    string sortVowels(string s) {
        int n = s.size();

        return storeAndFill(s, n);
    }
};
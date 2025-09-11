class Solution {
private:
    string storeSortFill(string s, int n) {
        // lambda to check vowel or not
        auto isVowel = [](char c) -> bool {
            char lc = tolower(c);
            return lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u';
        };

        // Store the vowels
        vector<char> vowels;
        for(char c : s){
            if(isVowel(c))
                vowels.push_back(c);
        }

        // Fill again after sorting
        sort(vowels.begin(), vowels.end());
        int i = 0;
        for(char& c : s){
            if(isVowel(c))
                c = vowels[i++];
        }

        return s;
    }


public:
    string sortVowels(string s) {
        int n = s.size();

        return storeSortFill(s, n);
    }
};
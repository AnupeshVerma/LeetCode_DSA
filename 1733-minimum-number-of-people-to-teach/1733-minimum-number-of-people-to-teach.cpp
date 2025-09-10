class Solution {
private:
    int greedy(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> usersToTeach;

        // Find users who can't communicate with each each other
        for(vector<int> friends : friendships) {
            bool canCommunicate = false;
            for(int lang1 : languages[friends[0] - 1]) {
                for(int lang2 : languages[friends[1] - 1]) {
                    if(lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate)
                    break;
            }
            if(!canCommunicate) {
                 cout<<friends[0] - 1<< friends[1] - 1<< "a   ";
                usersToTeach.insert(friends[0] - 1);
                usersToTeach.insert(friends[1] - 1);
            }
        }

        // Try teaching each language and find minimum
        int maxKnownLang = 0;
        vector<int> langCount(n+1, 0); // each languageknown by that much users
        for(int user : usersToTeach) {
            for(int lang : languages[user]) {
                langCount[lang]++;
                maxKnownLang = max(maxKnownLang, langCount[lang]);
            }
        }

        return usersToTeach.size() - maxKnownLang;
    }


public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        return greedy(n, languages, friendships);
    }
};
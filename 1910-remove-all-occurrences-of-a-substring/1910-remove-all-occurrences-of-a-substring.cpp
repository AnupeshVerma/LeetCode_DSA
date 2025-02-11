class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int m = part.size();

        for(char c : s) {
            ans.push_back(c);

            if(ans.size() >= m && c == part[m-1])
                if(ans.substr(ans.size() - m) == part)
                    ans.erase(ans.size() - m);
        }
        return ans;
    }
};
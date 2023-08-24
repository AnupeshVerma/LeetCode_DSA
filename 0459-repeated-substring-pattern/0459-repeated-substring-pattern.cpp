class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s;
        for(int i=0; i<s.size()-1; i++)
        {
            temp.erase(0, 1);
            temp.push_back(s[i]);
            if(temp == s)
                return true;
        }
        return false;
    }
};
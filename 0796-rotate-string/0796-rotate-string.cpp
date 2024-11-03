class Solution {
private: 
    string rotateHelper(string s) {
        string ans = s.substr(1, s.size()-1);
        ans.push_back(s[0]);
        return ans;
    }
    
    
    bool rotateAndCheck(string s, string goal, int n) {
        for(int i=0; i<n; i++) {
            s = rotateHelper(s);
            if(s == goal)
                return true;
        }
        return false;
    }
    
    
    
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size())
            return false;
        
        return rotateAndCheck(s, goal, n);
    }
};
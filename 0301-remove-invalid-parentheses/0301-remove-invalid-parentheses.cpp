class Solution {
private:
    int invalidBrackets(string s)
    {
        stack<char>st;     
        for(int i=0; i<s.size(); i++)
        {
            char top = st.empty() ? '/' : st.top();
            if(s[i]==')' && top=='(')
                st.pop();
            else if(s[i]==')' || s[i]=='(')
                st.push(s[i]);
        }
        return st.size();
    }
    
    unordered_set<string> ansString;
    unordered_set<string> allString;
    void checkValid(string s, int minDeletions)
    {
        if(allString.find(s) != allString.end())
            return;
        allString.insert(s);
        if(minDeletions == 0)
        {
            if(!invalidBrackets(s))
                ansString.insert(s);
            return;
        }
        
        for(int i=0; i<s.size(); i++)
        {
            string sAfterRemoval = s.substr(0,i) + s.substr(i+1);
            checkValid(sAfterRemoval, minDeletions-1);
        }
        return;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int minDeletions = invalidBrackets(s);
        
        checkValid(s, minDeletions);
        
        vector<string>ans;
        for(auto it:ansString)
            ans.push_back(it);
        
        return ans;
    }
};
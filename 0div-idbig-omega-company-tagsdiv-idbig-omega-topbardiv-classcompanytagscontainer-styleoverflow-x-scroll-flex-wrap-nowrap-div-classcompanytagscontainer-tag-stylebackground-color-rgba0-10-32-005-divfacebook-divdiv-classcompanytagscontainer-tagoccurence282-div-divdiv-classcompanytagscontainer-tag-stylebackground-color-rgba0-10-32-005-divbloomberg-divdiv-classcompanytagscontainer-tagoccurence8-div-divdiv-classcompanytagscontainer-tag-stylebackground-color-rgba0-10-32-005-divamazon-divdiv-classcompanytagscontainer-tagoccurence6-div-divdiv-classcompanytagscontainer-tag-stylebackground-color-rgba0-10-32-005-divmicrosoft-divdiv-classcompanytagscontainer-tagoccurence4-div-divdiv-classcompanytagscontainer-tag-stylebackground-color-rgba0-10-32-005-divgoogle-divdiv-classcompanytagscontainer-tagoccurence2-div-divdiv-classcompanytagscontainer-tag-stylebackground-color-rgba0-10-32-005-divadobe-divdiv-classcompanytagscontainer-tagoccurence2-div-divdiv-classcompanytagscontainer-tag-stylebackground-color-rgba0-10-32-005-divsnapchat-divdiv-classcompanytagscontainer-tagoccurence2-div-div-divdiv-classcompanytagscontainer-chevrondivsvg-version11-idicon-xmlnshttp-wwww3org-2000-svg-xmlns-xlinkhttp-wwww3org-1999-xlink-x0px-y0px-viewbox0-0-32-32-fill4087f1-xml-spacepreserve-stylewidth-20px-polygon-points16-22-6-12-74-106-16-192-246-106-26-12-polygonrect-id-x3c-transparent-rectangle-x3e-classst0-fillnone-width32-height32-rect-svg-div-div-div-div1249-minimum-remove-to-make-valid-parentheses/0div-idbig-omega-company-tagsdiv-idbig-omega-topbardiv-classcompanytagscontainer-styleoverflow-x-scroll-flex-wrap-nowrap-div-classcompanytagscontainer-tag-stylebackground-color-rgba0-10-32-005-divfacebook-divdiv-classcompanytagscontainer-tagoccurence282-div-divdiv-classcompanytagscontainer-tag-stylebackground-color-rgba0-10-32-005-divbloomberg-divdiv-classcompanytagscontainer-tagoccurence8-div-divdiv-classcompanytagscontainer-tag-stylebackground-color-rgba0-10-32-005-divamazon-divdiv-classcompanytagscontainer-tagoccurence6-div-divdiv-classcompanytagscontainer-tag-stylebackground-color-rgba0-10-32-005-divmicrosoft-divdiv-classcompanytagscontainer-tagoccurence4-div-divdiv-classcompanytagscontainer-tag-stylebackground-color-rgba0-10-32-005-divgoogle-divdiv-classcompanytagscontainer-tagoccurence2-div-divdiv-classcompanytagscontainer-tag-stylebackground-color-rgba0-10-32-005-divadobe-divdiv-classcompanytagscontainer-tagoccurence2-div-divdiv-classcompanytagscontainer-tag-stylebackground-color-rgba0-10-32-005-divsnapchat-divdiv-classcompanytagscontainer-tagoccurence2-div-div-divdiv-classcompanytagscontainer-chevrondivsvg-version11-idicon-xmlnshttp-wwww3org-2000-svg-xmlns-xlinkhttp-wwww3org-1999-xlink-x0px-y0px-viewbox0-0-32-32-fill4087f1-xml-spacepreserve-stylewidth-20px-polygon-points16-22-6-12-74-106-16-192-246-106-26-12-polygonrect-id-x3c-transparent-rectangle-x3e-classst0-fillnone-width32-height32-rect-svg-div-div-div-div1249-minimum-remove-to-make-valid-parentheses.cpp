class Solution {
private:
    string solve(string s)
    {
        stack<char>st;
        int leftParen=0;
        int rightParen=0;
        
        for(char c:s)
        {
            if(c=='(') leftParen++;
            if(c==')') rightParen++;
            
            if(rightParen > leftParen)
            {
                rightParen--;
                continue;
            }
            st.push(c);
        }
        
        string ans = "";
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            
            if(leftParen > rightParen && c=='(')
                leftParen--;
            else ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string usingStack(string s)
    {
        // Stack stores the indexes of '('
        unordered_set<int>remove;
        stack<int>st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')')
            {
                if(st.empty())
                    remove.insert(i);
                else
                    st.pop();
            }
        }
        
        while(!st.empty())
        {
            remove.insert(st.top());
            st.pop();
        }
        
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            if(remove.find(i) != remove.end())
                continue;
            ans += s[i];
        }
        return ans;
    }
public:
    string minRemoveToMakeValid(string s) {
        
        // return solve(s);
        
        return usingStack(s);
    }
};
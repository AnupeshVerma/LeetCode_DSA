class Solution {
public:
    string minRemoveToMakeValid(string s) {
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
};
class Solution {
private:
    string bruteForce(string s)
    {
        string ans = "";
        stack<int> st;
        for(char ch : s)
        {
            if(ch == '(')
                st.push(ans.size());
            else if(ch == ')')
            {
                int start = st.top();
                st.pop();
                reverse(ans.begin()+start, ans.end());
            }
            else
                ans += ch;
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        
        return bruteForce(s);
    }
};
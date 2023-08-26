class Solution {
public:
    int scoreOfParentheses(string s) {
        // int open = 0, score=0;
        // for(int i=0; i<s.size(); i++)
        // {
        //     if(s[i] == '(')
        //         open++;
        //     else
        //     {
        //         open--;
        //         if(s[i-1] == '(')
        //             score += pow(2, open);
        //     }
        // }
        // return score;
        
        stack<int> st;
        int score = 0;
        
        for(auto it:s)
        {
            int val = 0;
            if(it == '(')
                st.push(0);
            else
            {
                while(st.top() != 0)
                {
                    val += st.top();
                    st.pop();
                }
                val = max(2*val, 1);
                st.pop();
                st.push(val);
            }
        }
        while(!st.empty())
        {
            score += st.top();
            st.pop();
        }
        
        return score;
    }
};
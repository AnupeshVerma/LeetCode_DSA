class Solution {
public:
    int solve(string s)
    {
        int open=0, depth=0;
        for(char c:s)
        {
            if(c == '(')
                open++;
            else if(c == ')')
                open--;
            depth = max(open, depth);
        }
        return depth;
    }
public:
    int maxDepth(string s) {
        
        return solve(s);
        
        // We can also use stack for this
    }
};
class Solution {
public:
    bool usingStack(string s)
    {
        stack<int>openParen;
        stack<int>star;
        
        
        for(int i=0; i<s.size(); i++)
        {
            char c = s[i];
            if(c == '*')
                star.push(i);
            else if(c == '(')
                openParen.push(i);
            else if(c == ')')
            {
                if(!openParen.empty())
                    openParen.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        while(!openParen.empty() && !star.empty())
        {
            if(star.top() > openParen.top())
            {
                star.pop();
                openParen.pop();
            }
            else
                return false;
        }
        return openParen.empty() ? true : false;
        
    }
    
    int solve(string s)
    {
        int low = 0;   
        int high = 0;

    for (const char c : s) {
      switch (c) {
        case '(':
          ++low;
          ++high;
          break;
        case ')':
          low = max(0, --low);
          --high;
          break;
        case '*':
          low = max(0, --low);
          ++high;
          break;
      }
      if (high < 0)
        return false;
    }
    return low == 0;   
    }
    bool checkValidString(string s) {
        
        return usingStack(s);
    }
};
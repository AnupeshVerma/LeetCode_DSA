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
    
    int usingCounters(string s)
    {
        int leftMax=0, leftMin=0;
        for(char c:s)
        {
            if(c == '(')
            {
                leftMin++;
                leftMax++;
            }
            
            if(c == ')')
            {
                leftMin = max(0, --leftMin);
                leftMax--;
            }
            
            if(c == '*')
            {
                leftMin = max(0, --leftMin);
                leftMax++;
            }
            
            // if more closing brackets than opening
            if(leftMax < 0)
                return false;
        }
        
        return leftMin == 0;
    }
    
    bool checkValidString(string s) {
        
        // return usingStack(s);
        
        return usingCounters(s);
    }
};
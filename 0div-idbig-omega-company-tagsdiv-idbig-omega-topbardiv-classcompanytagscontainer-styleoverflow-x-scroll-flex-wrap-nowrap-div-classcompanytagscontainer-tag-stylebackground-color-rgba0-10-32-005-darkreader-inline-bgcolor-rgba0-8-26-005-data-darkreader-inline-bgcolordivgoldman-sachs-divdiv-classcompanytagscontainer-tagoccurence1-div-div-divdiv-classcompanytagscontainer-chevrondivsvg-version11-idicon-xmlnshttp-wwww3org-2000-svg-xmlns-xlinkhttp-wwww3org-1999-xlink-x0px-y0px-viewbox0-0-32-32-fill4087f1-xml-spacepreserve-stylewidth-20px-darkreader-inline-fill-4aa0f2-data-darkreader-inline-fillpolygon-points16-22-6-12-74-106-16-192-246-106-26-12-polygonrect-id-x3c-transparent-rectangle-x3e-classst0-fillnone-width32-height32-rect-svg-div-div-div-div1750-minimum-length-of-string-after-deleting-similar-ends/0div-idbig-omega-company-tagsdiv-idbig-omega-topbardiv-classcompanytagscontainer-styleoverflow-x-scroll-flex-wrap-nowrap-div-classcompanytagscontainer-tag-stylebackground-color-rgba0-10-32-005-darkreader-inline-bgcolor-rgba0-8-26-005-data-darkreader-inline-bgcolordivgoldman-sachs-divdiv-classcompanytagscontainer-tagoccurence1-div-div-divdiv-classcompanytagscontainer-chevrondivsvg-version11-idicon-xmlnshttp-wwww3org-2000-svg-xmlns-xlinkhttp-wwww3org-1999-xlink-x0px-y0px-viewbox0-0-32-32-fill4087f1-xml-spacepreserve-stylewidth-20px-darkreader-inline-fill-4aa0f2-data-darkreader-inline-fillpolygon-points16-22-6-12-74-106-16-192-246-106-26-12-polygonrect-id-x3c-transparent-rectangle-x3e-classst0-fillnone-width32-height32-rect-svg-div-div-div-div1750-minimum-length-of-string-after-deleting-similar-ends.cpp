class Solution {
private:
    int twoPointer(string s)
    {
        int n = s.size();
        int front=0, back=n-1;
        
        while(front<back)
        {
            if(s[front] != s[back] && front<back)
                break;
            
            int prefix=1, suffix=1;
            while(s[front+1]==s[front++] && front<back)
            {
                prefix++;
            }
            while(s[back-1]==s[back--] && front<back)
                suffix++;
            n = n-prefix-suffix;
        }
        return n;
    }
public:
    int minimumLength(string s) {
        return twoPointer(s);
    }
};
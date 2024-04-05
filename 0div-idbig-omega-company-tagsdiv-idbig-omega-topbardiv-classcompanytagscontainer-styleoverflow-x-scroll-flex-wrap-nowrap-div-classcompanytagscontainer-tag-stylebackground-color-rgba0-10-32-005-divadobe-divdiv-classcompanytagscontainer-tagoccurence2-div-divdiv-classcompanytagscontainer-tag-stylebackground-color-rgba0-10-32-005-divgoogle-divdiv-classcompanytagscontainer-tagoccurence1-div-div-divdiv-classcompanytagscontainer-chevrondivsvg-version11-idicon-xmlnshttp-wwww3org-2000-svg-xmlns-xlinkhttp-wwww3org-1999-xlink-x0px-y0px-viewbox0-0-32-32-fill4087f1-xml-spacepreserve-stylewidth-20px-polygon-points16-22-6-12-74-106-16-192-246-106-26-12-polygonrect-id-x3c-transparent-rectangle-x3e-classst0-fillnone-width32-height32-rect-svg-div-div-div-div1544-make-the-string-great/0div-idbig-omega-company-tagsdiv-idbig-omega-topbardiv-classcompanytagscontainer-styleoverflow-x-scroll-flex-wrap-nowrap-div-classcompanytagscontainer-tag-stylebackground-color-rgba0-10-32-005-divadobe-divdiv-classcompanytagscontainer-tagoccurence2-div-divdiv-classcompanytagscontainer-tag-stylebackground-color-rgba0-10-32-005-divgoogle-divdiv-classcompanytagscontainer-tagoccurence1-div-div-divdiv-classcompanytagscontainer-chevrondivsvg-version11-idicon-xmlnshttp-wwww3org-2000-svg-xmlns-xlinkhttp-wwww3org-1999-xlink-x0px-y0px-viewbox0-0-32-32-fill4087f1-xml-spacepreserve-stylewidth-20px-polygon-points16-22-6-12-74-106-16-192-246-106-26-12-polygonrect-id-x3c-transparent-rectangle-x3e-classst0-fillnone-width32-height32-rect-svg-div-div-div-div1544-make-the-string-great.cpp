class Solution {
private:
    string bruteForce(string s)
    {
        for(int i=0; i<s.size()-1; i++)
        {
            if(abs(s[i]-s[i+1]) == 32)
            {
                s = s.erase(i,2);
                if(s=="")
                    break;
                i = -1;
            }
             
        }
        return s;
    }
public:
    string makeGood(string s) {
        int n = s.size();
        if(n==1)
            return s;
        
        return bruteForce(s);
    }
};
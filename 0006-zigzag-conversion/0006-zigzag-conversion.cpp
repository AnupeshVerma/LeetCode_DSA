class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> v(numRows, "");
        int i=0, n = s.size();
        
        while(i<n)
        {
            for(int j=0; i<n && j<numRows; j++)
                v[j].push_back(s[i++]);
            
            for(int j=numRows-2; i<n && j>0; j--)
                v[j].push_back(s[i++]);
        }
        string ans="";
        for(auto i:v)
            ans+=i;
        
        return ans;
            
    }
};
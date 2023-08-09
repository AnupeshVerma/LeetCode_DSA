class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        // By observation, you will find that string can be sorted in ascending order
        // if k>1 but if k=1, you can only rotate the string
        
        if(k>1)
        {
            sort(s.begin(), s.end());
            return s;
        }
//         Rotate the string fully and check
        int n = s.size();
        string ans = s;
        for(int i=0; i<s.size(); i++)
        {
            s = s.substr(1, n-1) + s[0];
            ans = min(ans, s);
        }
        return ans;
    }
};
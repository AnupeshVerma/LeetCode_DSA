class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int ans = 0;
      
        int count = m/n + 2;  // For front and back matching
        string temp = "";
        while(count--)
        {
           
            temp+=a;
            ans++;
            if(temp.find(b) != -1)
                return ans;
        }
        return -1;
    }
};
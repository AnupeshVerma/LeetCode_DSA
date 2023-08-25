class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";
        
        if(num==1)
            return "A";
        while(num)
        {
            num--;
            ans += 'A' + num%26;
            num /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
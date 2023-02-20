class Solution {
public:
    int myAtoi(string s) {
        double ans = 0, i = 0;
        bool neg = false;
        
        while(s[i] == ' ')
            i++;
       
        if(s[i] =='+' || s[i] == '-')
        {
            if(s[i] == '-')
                neg = true;
            i++;
        }
        while(i < s.size())
        { 
            if(s[i] >= '0' && s[i] <= '9')
            {
                int num = s[i] - '0';
                ans = ans*10 + num;  
            }
            else break;
            i++;
        }
        if(neg == true)
            ans = ans*(-1);
        // Clamping
        ans = ans > INT_MAX ? INT_MAX : ans;
        ans = ans < INT_MIN ? INT_MIN : ans;
        
        return int(ans);
    }
};
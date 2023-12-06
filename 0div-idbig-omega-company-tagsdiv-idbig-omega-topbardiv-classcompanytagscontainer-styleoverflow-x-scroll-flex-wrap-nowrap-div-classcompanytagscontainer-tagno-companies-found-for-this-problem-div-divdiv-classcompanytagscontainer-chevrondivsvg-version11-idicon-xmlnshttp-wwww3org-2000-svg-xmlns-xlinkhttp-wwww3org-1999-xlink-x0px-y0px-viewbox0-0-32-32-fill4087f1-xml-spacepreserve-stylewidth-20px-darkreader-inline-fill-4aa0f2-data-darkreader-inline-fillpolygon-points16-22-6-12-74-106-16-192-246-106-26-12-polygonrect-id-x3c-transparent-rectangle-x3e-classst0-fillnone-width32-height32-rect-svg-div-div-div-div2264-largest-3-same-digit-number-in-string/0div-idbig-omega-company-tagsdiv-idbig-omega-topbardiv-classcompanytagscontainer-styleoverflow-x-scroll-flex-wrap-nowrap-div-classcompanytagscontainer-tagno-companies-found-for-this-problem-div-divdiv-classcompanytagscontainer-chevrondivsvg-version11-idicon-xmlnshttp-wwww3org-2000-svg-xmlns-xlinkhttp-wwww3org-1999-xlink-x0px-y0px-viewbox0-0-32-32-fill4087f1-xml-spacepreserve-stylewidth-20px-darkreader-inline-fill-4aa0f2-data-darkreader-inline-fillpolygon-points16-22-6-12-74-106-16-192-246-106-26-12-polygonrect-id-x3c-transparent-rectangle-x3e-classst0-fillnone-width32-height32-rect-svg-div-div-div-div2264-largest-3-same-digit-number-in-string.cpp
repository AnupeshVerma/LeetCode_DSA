class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = INT_MIN;
        bool allZero = false;
        
        for(int i=0; i<num.size()-2; i++)
        {
            if(num[i] == num[i+1] && num[i+1]==num[i+2])
            {
                if(num[i] == 0)
                    allZero = true;
                string sub = num.substr(i, 3);
                int newAns = stoi(sub);
                
                ans = max(ans, newAns);
                
            }
        }
        if(ans ==0)
            return "000";
        else if(ans == INT_MIN)
            return "";
        
        return to_string(ans);
    }
};
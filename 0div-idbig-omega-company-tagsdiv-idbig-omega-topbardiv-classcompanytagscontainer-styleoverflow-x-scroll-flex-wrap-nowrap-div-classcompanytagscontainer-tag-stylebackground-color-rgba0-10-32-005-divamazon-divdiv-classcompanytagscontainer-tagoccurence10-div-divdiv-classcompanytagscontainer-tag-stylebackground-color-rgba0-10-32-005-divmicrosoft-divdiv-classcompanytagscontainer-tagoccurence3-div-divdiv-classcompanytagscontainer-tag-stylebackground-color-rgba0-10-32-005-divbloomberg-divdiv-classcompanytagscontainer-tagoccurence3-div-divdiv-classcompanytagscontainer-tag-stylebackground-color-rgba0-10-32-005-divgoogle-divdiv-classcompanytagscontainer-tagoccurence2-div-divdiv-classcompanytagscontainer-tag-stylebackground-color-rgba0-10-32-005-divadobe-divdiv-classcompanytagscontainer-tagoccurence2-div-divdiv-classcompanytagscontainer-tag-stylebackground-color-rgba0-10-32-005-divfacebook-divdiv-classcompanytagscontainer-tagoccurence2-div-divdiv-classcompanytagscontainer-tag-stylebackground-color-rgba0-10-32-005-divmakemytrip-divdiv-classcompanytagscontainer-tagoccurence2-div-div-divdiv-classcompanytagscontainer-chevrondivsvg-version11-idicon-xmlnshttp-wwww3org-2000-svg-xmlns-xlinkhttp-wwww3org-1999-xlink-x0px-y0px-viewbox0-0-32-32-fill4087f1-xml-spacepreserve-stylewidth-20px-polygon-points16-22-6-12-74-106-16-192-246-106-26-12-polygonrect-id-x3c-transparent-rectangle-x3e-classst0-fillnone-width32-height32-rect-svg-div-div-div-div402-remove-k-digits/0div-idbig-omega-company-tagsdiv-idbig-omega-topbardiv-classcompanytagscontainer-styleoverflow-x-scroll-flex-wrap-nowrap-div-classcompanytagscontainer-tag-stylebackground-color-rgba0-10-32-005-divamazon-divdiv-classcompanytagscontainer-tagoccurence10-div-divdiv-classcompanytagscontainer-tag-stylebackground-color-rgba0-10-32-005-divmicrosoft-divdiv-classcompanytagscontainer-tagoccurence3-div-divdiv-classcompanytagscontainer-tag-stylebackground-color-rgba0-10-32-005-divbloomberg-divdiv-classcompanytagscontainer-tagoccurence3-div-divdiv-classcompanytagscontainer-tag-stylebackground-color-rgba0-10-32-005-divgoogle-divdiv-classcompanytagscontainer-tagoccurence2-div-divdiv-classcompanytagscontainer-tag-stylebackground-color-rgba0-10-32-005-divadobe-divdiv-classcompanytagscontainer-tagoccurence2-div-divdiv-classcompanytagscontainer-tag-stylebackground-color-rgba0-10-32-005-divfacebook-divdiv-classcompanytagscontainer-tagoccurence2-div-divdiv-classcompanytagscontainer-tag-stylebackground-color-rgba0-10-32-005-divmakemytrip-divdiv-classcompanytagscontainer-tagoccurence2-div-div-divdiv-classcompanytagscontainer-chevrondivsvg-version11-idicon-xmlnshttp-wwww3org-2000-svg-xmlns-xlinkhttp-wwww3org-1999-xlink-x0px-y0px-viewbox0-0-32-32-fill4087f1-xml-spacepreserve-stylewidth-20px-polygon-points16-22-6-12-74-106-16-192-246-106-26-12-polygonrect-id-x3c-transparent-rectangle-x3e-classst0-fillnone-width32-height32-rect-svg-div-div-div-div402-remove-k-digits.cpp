class Solution {
private:
    string solve(string num, int k)
    {
        
        for(int i=0; i<num.size() && k>0; i++)
        {
            while (k > 0 && i < num.size()-1 && num[i]>num[i+1])
            {
                num.erase(num.begin()+i);
                i = max(0, i-1);
                k--;
            }
        }
        
        // remove from end if remaining
       if(k>0)
           num.erase(num.end()-k, num.end());
        
        // remove leeading zeroes
        while(num.size() >0 and num[0]=='0')
             num.erase(num.begin());
        
        return num=="" ? "0" : num;
            
    }
    
    string usingStack(string num, int k)
    {
        stack<char>st;
        
        for(char c : num)
        {
            while(!st.empty() && st.top() > c && k>0)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        // remove remaining digits
        while(k>0)
        {
            st.pop();
            k--;
        }
        
        // create ans string
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
         // remove leeading zeroes
        while(ans.size() >0 and ans[0]=='0')
             ans.erase(ans.begin());
        
        return ans.empty() ? "0" : ans;
    }
public:
    string removeKdigits(string num, int k) {
        
        // return solve(num, k);
        
        return usingStack(num, k);
    }
};
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
public:
    string removeKdigits(string num, int k) {
        
        return solve(num, k);
    }
};
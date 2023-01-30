class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans = "";
        int asize = a.size()-1;
        int bsize = b.size()-1;
        int carry = 0;
        
        while(asize>=0 || bsize>=0)
        {
            int sum = carry;
            
            if(asize>=0) sum +=a[asize--]-'0';
            if(bsize>=0) sum +=b[bsize--]-'0';
            
            if(sum>1)
                carry = 1;
            else carry = 0;
            ans += to_string(sum%2);
        }
       if(carry)
       {
           ans+=to_string(carry);
       }
        reverse(ans.begin(), ans.end());
                
        return ans;
    }  
};
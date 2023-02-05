class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> temp(26, 0);
        
        for(auto i:p)
            temp[i-'a']++;
        
         int n1=s.size(), n2=p.size();
        for(int i=0; i<=n1-n2; i++)
        {
            vector<int> temp1(26, 0);
            for(int j=i; j<n2+i; j++)
                temp1[s[j]-'a']++;
            
            if(temp == temp1)
                ans.push_back(i);
            
        }
        return ans;
        
    }
};
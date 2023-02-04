class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0);
        
        for(auto i:s1)
            v1[i-'a']++;
        
        int n1=s1.size(), n2=s2.size();
        
        for(int i=0; i<=n2-n1; i++)
        {
            vector<int>v2(26, 0);
            for(int j=i; j<n1+i; j++)
                v2[s2[j]-'a']++;
            
            if(v2 == v1)
                return true;
        }
        return false;
    }
};
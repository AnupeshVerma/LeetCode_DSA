class Solution {
private:
    int solve(string v1, string v2)
    {
        int dot1=0, dot2=0;
        for(auto c : v1)
            c=='.' ? dot1++ : 0;
         for(auto c : v2)
            c=='.' ? dot2++ : 0;
        
        if(dot1 < dot2)
            while(dot1 != dot2)
            {
                v1 += ".0";
                dot1++;
            }
        if(dot2 < dot1)
            while(dot2 != dot1)
            {
                v2 += ".0";
                dot2++;
            }
        
        int m=v1.size(), n=v2.size();
        int i=0, j=0;
        while(i<m and j<n)
        {
            string rev1="";
            while(v1[i] != '.' and i<m)
                rev1 += v1[i++];
            
            string rev2="";
            while(v2[j] != '.' and j<n)
                rev2 += v2[j++];
            
            if(stoi(rev2) > stoi(rev1))
                return -1;
            if(stoi(rev2) < stoi(rev1))
                return 1;
            i++;
            j++;
        }
        return 0;
    }
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        
        return solve(version1, version2);
    }
};
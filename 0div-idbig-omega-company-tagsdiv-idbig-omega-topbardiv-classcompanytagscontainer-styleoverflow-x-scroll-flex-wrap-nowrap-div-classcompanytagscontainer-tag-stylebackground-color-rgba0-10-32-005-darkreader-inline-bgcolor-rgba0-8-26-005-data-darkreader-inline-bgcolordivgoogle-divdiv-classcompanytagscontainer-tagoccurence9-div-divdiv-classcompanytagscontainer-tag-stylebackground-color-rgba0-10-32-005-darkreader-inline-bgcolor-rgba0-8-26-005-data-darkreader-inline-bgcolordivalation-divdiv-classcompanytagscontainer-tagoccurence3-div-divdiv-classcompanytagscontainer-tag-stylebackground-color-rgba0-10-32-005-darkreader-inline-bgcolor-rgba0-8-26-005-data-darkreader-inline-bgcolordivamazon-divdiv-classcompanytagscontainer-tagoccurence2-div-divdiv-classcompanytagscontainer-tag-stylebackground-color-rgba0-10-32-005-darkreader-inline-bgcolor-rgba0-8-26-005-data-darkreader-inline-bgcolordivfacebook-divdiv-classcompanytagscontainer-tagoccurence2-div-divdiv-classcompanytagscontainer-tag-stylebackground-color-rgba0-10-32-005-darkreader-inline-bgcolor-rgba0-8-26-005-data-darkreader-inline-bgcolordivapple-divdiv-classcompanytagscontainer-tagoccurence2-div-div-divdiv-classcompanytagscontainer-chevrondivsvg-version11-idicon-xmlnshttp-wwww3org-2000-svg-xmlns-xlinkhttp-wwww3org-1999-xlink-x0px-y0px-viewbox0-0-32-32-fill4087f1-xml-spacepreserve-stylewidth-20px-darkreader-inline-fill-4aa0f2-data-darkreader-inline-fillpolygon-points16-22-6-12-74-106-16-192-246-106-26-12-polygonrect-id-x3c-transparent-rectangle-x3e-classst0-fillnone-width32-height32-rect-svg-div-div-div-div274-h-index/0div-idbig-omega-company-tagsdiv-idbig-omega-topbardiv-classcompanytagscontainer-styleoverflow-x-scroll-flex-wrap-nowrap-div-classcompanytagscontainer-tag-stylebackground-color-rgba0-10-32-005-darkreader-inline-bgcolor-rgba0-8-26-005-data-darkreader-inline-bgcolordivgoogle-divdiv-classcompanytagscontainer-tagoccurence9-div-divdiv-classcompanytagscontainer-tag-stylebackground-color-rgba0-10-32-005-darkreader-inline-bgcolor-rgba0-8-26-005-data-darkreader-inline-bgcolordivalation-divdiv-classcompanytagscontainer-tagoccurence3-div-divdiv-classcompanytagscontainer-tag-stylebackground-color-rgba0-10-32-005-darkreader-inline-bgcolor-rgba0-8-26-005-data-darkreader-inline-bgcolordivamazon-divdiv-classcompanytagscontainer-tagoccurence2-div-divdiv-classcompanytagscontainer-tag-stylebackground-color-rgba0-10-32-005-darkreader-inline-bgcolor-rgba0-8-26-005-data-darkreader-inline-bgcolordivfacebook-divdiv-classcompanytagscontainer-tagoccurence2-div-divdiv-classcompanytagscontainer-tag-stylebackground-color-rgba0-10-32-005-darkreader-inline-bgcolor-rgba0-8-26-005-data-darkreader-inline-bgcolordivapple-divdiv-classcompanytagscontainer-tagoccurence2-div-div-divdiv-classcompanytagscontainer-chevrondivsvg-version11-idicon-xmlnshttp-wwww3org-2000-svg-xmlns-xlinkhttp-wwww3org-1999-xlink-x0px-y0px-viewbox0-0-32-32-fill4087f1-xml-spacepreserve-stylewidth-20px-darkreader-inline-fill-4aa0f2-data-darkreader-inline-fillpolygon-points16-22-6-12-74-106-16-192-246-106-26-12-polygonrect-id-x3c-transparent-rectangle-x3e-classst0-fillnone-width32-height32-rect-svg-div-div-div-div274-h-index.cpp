class Solution {
public:
    int bruteForce(vector<int>& cit)
    {
        int n = cit.size();
        int ans = 0;
        sort(cit.begin(), cit.end());
        
        for(int i=1; i<=n; i++)
        {
            if(cit[n-i] >= i)
                ans = i;
            else
                break;
        }
        
        return ans;
    }
    int hIndex(vector<int>& citations) {
        
        return bruteForce(citations);
    }
};
class Solution {
public:
    int nTime(vector<int>& cit)
    {
        int ans = 0, n=cit.size();
        
        for(int i=n-1; i>=0; i--)
        {
            if(cit[i] >= n-i)
                ans = n-i;
            else
                break;
        }
        return ans;
    }
    int hIndex(vector<int>& citations) {
        
        return nTime(citations);
    }
};
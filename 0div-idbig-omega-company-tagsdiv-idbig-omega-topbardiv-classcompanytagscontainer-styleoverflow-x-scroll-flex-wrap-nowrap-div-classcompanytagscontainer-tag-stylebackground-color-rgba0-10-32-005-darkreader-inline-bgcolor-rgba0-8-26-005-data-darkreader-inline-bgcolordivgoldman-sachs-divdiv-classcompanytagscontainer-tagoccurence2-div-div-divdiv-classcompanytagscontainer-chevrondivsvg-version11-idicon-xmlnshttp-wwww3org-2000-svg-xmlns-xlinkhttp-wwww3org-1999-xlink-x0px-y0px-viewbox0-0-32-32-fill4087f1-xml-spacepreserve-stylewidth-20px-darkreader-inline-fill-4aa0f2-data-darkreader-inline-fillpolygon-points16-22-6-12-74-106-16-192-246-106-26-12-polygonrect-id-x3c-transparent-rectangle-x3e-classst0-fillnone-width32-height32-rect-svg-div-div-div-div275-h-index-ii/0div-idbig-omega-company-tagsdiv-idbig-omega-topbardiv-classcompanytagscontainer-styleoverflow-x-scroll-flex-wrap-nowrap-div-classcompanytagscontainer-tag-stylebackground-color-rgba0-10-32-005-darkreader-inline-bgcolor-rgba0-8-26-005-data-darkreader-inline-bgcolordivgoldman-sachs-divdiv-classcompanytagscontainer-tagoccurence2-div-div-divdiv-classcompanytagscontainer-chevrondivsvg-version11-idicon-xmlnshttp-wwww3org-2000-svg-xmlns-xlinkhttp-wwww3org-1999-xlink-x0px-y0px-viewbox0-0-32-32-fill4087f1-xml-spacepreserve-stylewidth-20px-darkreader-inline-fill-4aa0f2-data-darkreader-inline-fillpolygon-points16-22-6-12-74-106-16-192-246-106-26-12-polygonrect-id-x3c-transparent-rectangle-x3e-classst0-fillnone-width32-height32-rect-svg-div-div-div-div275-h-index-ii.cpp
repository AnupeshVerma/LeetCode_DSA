class Solution {
private:
    int nTime(vector<int>& cit, int n)
    {
        int ans = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            if(cit[i] >= n-i)
                ans = n-i;
            else
                break;
        }
        return ans;
    }
    
    int lognTime(vector<int>&cit, int n)
    {
        int low=0, high=n-1, ans=0;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(cit[mid] >= n-mid)
            {
                ans = n-mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // return nTime(citations, n);
        
        return lognTime(citations, n);
    }
};
class Solution {
private: 
    int bruteForce(vector<int>& h, int n)
    {
        int count = 0;
        vector<int> expected = h;
        
        sort(h.begin(), h.end());
        for(int i=0; i<n; i++)
        {
            if(h[i] != expected[i])
                count++;
        }
        return count;
    }
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        
        return bruteForce(heights, n);
    }
};
class Solution {
private:
    int extraSpace(vector<int>& height, int n)
    {
        vector<int> maxLeft;
        maxLeft.push_back(0);
        for(int i=0; i<n; i++)
        {
            maxLeft.push_back(max(height[i], maxLeft.back()));
            cout<<maxLeft[i]<<" ";
        }
        cout<<endl;
        
        vector<int> maxRight;
        maxRight.push_back(0);
        for(int i=n-1; i>0; i--)
            maxRight.push_back(max(height[i], maxRight.back()));
        reverse(maxRight.begin(), maxRight.end());
        for(int i=0; i<n; i++)
        {
            cout<<maxRight[i]<<" ";
        }
              cout<<endl;
        
        vector<int> minLeftRight;
        for(int i=0; i<n; i++)
        {
            minLeftRight.push_back(min(maxLeft[i], maxRight[i]));
            cout<<minLeftRight[i]<<" ";
        }
        cout<<endl;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int diff = minLeftRight[i]-height[i];
            ans += diff>0 ? diff : 0;
            cout<<diff<<" ";
        }
        
        return ans;
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        return extraSpace(height, n);
        
    }
};
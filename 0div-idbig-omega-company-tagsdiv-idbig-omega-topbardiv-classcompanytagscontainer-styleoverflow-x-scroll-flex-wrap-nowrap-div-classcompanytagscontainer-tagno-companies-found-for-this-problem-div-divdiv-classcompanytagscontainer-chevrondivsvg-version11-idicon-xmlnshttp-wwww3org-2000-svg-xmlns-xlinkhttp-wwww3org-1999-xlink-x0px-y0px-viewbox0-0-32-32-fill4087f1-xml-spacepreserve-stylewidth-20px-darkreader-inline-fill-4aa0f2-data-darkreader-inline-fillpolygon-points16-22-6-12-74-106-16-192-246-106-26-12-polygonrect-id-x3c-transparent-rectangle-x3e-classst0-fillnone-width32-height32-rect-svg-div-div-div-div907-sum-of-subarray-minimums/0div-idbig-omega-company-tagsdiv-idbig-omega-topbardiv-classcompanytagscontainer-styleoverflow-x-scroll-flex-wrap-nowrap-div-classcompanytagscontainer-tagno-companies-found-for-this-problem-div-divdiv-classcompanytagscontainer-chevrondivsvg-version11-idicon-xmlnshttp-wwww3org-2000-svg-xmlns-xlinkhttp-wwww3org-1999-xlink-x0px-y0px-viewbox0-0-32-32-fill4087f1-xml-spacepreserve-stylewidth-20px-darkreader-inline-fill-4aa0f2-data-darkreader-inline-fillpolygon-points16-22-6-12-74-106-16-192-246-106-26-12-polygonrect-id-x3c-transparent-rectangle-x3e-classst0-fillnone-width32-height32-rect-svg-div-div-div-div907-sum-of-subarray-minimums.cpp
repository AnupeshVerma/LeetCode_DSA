class Solution {
public:
    long mod = 1e9 + 7;
//     Brute Force
    int sumOfMins(vector<int>&arr)
    {
        if(arr.size() == 0)
            return 0;
        long ans = 0;
        
        for(int i=0; i<arr.size(); i++)
        {
            int mini = arr[i];

            for(int j=i; j<arr.size(); j++)
            {
                mini = min(arr[j], mini);
                ans += mini;
                
            }
        }
        return (int)ans%mod;
    }
    
    int stackMethod(vector<int>& arr)
    {
        int n = arr.size();
        long ans = 0;
        stack<int> s1, s2;  // Stack to store indexes of next smaller and prev smaller
        // rightGroup store the no. of elements between arr[i] and next smaller np.
        // leftGroup  store the n0. of elements between arr[i] and previous smaller no.
        vector<int> rightGroup(n), leftGroup(n);
        
        for(int i=0; i<n; i++)
        {
            leftGroup[i] = i;
            rightGroup[i]= n-1-i;
        }
        
//         Calculate next smaller groups
        for(int i=0; i<n; i++)
        {
            
            while(!s1.empty() && arr[i]<arr[s1.top()])
            {
                int comparingIndex = s1.top();
                rightGroup[comparingIndex] = i-comparingIndex-1;
                s1.pop();
            }
            s1.push(i);
        }
//         Calculate prev smaller group
        for(int i=n-1; i>=0; i--)
        {
            
            while(!s2.empty() && arr[i] <= arr[s2.top()])
            {
                int comparingIndex = s2.top();
                leftGroup[comparingIndex] = comparingIndex-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        
        for(int i=0; i<n; i++)
        {
            long long totalSubsets = (leftGroup[i]+1)*(rightGroup[i]+1);
            long long sumOfMinsInSubsets = arr[i]*totalSubsets;
            ans = (ans + sumOfMinsInSubsets)%mod;
        }
        return (int)ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // return sumOfMins(arr);
        return stackMethod(arr);
        
        
    }
};
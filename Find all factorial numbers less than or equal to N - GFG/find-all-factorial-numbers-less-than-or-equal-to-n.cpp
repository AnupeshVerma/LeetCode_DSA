//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<long long> ans;
    long long fac =1;
    int count=1;
    
    void fact(long long n ){
       if(fac > n)
       {
           ans.pop_back();
            return;
       }
       fac = fac*count++;
       ans.push_back(fac);
       fact(n);
    }
    
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        fact(N);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends
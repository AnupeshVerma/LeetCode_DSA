//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
       int b=0,a=0,l=0,o=0,n=0;
       for(int i=0;i<s.size();i++){
           if(s[i]=='b') b++;
           else if(s[i]=='a') a++;
           else if(s[i]=='l') l++;
           else if(s[i]=='o') o++;
           else if(s[i]=='n') n++;
       }
       int x = min(b,min(a,n));
       int y = min(l,o);
       y = y/2;
       return min(x,y);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
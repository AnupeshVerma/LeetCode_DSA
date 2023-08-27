class Solution {
private:
    vector<long> fib;
    set<int>fibSet;
    void fibo(int k)
    {
        fib.push_back(1);
        fib.push_back(1);
        while(fib.back() <= k)
            fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
    
public:
    int findMinFibonacciNumbers(int k) {
        
        fibo(k);
        // for(auto it:fib)
        //     cout<<it<<" ";
        
         int i = fib.size()-1;
        int count = 1, num = fib[--i];
        cout<<num;
        
        while(i>=0)
        {
            if(num + fib[i] <= k)
            {
                num += fib[i];
                count++;
            }
             i--;   
            if(num == k)
                return count;
        }
        return count;
        
    }
};
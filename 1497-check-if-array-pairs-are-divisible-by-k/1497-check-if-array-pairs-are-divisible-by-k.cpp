class Solution {
private:
    bool bruteForce(vector<int>& arr, int k, int n)
    {
        vector<int> freq(k, 0);
        for(int a:arr){
            int rem = (a%k + k)%k;
            freq[rem]++;
        }
        
        if(freq[0]%2 != 0)
            return false;
        
        for (int i=1; i<=k/2; i++)
        {
            if(freq[i] != freq[k-i])
                return false;
        }
        return true;
    }
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        
        return bruteForce(arr, k, n);
    }
};
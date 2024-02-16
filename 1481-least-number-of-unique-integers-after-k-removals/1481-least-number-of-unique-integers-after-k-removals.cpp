class Solution {
private:
    int bruteForce(vector<int> &arr, int k)
    {
        unordered_map<int, int>freq;
        vector<int> frequencies;
        
        for(auto num:arr)
            freq[num]++;
        
        for(auto i:freq)
            frequencies.push_back(i.second);
        
        sort(frequencies.begin(), frequencies.end());
        int removed = 0;
        for(auto f:frequencies)
            if(f <= k)
            {
                k -= f;
                removed++;
            }
        return freq.size() - removed;
    }
    
    
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        
        return bruteForce(arr, k);
    }
};
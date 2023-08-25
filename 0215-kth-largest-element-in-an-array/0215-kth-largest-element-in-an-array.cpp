class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int, greater<int>>mp;
        for(int i : nums)
            mp[i]++;
        
        for(auto it:mp)
        {
            if(k <= it.second)
                return it.first;
            else
                k-= it.second;
        }
        return -1;
    }
};
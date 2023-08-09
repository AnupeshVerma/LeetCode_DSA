class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>>mp;
        
        for(int i=0; i<n; i++)
            mp[nums[i]].push_back(i);
        
        
        for(auto [num, ind] : mp)
        {
//             put onr more index to find distance if only one index is available
            ind.push_back(ind[0]+n);
            int num_between = 0;
                
            for(int i=1; i<ind.size(); i++)
            {
                num_between = max(ind[i]-ind[i-1]-1, num_between);
            }
            int time = (num_between+1)/2;
            ans = min(time, ans);
        }
        return ans;
            
    }
};
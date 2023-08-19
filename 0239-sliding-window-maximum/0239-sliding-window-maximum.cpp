class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
//         Brute Force (cause TLE)
        // vector<int>ans;
        // for(int i=0; i<n-k+1; i++)
        // {
        //     int maxi = *max_element(nums.begin()+i, nums.begin()+i+k);
        //     ans.push_back(maxi);
        // }
        // return ans;
        
//                                                 
        map<int, int>mp;
        vector<int>ans;
        int maxi = INT_MIN;
        for(int i=0; i<k; i++)
        {
            mp[nums[i]]++;
            maxi = max(nums[i], maxi);
        }
        
        for(int i=0; i+k<n; i++)
        {
            ans.push_back(mp.rbegin()->first);
            mp[nums[i+k]]++;
            mp[nums[i]]--;
            
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
        }
        ans.push_back(mp.rbegin()->first);
        return ans;
    }
};
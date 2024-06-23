class Solution {
private:
    int slidingWindow(vector<int>& nums, int limit, int n)
    {
        int maxLength=0;
        int start=0, end=0;
        map<int, int>mp;
        
        for(int end=0; end<n; end++)
        {
            mp[nums[end]]++;
            int minNum = mp.begin()->first;
            int maxNum = mp.rbegin()->first;
            
            int diff = abs(maxNum - minNum);
            while(diff > limit)
            {   
                int num = nums[start++];
                mp[num]--;
                if(mp[num]==0)
                    mp.erase(num);
                
                diff = abs(mp.begin()->first - mp.rbegin()->first);
            }
        
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        return slidingWindow(nums, limit, n);
    }
};
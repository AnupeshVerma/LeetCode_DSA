class Solution {
private:
    int bruteForce(vector<int>& nums, int n)
    {
        int ans = -1;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(nums[i] == -nums[j])
                    ans = max(ans, abs(nums[i]));
        return ans;
    }
    int usingSet(vector<int>& nums, int n)
    {
        unordered_set<int> st;
        for(auto num : nums)
            st.insert(num);
        
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=0; i--)
            if(nums[i]>0 and st.find(-nums[i]) != st.end())
                return nums[i];
        
        return -1;
    }
    
    int twoPointer(vector<int>& nums, int n)
    {
        sort(nums.begin(),nums.end());
        int left=0, right=n-1;
        
        while(left<right)
        {
            if(nums[left] == -1*nums[right])
                return nums[right];
            else if(nums[left] < -nums[right])
                left++;
            else
                right--;
        }
        return -1;        
    }
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        
        return bruteForce(nums, n);
        
        // return usingSet(nums, n);
        
        return twoPointer(nums, n);
    }
};
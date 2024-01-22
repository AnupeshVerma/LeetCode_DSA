class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1, 0);
        vector<int> ans;
        
        for(auto num : nums)
        {
            hash[num]++;
            if(hash[num] == 2)
                ans.push_back(num);
        }
        
        for(int i=1; i<=n; i++)
            if(hash[i] == 0)
                ans. push_back(i);
        
        return ans;
    }
};
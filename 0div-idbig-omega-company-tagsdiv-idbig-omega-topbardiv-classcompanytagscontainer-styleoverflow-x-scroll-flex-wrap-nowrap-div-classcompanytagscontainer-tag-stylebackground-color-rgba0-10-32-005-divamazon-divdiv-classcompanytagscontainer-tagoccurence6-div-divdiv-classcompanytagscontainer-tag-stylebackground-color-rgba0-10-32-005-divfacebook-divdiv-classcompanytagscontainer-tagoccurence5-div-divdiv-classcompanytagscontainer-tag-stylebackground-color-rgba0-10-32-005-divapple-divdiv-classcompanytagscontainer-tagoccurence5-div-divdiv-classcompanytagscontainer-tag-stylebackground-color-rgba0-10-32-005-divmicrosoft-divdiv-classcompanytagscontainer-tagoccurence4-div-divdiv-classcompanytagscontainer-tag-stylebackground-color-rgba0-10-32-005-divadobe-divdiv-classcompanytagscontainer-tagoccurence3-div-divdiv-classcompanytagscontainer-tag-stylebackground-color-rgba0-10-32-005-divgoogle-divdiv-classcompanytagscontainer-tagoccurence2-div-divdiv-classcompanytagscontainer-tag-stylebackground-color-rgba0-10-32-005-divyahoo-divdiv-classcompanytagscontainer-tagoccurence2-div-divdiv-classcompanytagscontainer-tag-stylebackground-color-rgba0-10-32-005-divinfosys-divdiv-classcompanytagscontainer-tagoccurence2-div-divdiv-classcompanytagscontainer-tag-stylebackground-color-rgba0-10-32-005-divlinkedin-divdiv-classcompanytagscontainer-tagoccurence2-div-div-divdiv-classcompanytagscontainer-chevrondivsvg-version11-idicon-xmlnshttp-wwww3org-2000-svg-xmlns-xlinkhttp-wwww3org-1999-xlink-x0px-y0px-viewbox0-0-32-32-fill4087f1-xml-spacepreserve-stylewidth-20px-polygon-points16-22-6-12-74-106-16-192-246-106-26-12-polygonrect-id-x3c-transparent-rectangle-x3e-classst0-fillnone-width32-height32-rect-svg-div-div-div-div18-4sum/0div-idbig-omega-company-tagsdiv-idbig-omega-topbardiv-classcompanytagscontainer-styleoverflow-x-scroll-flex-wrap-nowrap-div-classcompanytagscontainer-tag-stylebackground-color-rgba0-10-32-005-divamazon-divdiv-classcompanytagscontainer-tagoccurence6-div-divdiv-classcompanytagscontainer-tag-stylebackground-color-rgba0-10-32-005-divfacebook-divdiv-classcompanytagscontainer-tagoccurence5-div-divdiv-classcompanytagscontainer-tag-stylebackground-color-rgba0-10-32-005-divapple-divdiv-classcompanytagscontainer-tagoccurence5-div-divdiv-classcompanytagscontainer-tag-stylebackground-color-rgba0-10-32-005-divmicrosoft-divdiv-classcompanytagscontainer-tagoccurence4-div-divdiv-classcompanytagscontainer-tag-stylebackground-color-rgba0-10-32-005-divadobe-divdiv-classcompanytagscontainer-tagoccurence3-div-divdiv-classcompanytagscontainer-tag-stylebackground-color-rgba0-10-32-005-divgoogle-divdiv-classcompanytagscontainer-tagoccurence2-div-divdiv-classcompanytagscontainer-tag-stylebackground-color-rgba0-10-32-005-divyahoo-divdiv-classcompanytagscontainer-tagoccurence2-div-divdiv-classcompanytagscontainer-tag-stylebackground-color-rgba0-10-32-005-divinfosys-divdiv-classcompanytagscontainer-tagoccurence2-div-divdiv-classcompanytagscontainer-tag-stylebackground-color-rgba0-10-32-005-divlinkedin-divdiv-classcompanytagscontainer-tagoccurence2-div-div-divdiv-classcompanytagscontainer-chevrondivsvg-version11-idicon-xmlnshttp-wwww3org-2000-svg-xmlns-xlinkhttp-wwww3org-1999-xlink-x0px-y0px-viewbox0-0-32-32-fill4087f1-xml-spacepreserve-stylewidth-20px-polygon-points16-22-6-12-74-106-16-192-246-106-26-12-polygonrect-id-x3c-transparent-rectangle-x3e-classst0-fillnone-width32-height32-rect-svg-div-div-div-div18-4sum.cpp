class Solution {
private:
    vector<vector<int>> bruteForce(vector<int>&nums, int target, int n)
    {
        set<vector<int>>distinctSet;
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                for(int k=j+1; k<n; k++)
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    for(int l=k+1; l<n; l++)
                        if(sum + nums[l] == target)
                        {
                            vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            distinctSet.insert(temp);
                        }
                }
        vector<vector<int>>ans(distinctSet.begin(), distinctSet.end());
        return ans;
    }
    vector<vector<int>> threeLoop(vector<int>&nums, int target, int n)
    {
        set<vector<int>>distinctSet;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                unordered_set<int>prevVal;
                for(int k=j+1; k<n; k++)
                {
                   int fourth = target - nums[i]-nums[j]-nums[k];
                    if(prevVal.find(fourth) != prevVal.end())
                    {
                        vector<int>temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        distinctSet.insert(temp);
                    }
                    prevVal.insert(nums[k]);
                }
            }
        vector<vector<int>>ans(distinctSet.begin(), distinctSet.end());
        return ans;
    }
    
//     Two Pointer approach
    vector<vector<int>> twoPointer(vector<int>&nums, int target, int n)
    {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            if(i>0 and nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++)
            {
                if(j>i+1 and nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];


                    if(sum > target) l--;
                    else if(sum < target) k++;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
       return ans;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // return bruteForce(nums, target, n);
        
        // return threeLoop(nums, target, n);
        
        return twoPointer(nums, target, n);
    }
};
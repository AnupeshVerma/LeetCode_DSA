class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        if(n==0)
            return ans;
        int first=nums[0], last = nums[0];
        
        for(int i=1; i<n; i++)
        {
            
            if(nums[i-1] +1 == nums[i])
                last = nums[i];
            else
            {
                if(first == last)
                    ans.push_back(to_string(last));
                else
                {
                    string temp = to_string(first) + "->" + to_string(last);
                    ans.push_back(temp);
                }
                first = nums[i];
                last = nums[i];
            }
        }
        if(first==last) {
                  ans.push_back(to_string(last));
                  
              }
              else{
                 ans.push_back(to_string(first) + "->" + to_string(last));
              }
              
        return ans;
    }
};
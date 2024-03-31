class Solution {
private:
    long long bruteForce(vector<int>& nums, int minK, int maxK, int n)
    {
        int count = 0;
        
        for(int i=0; i<n; i++)
        {   vector<int>subArray;
            subArray.push_back(nums[i]);
            for(int j=i+1; j<n; j++)
            {
                subArray.push_back(nums[j]);
            
                 int maxElement = *max_element(subArray.begin(), subArray.end());
                 int minElement = *min_element(subArray.begin(), subArray.end());
                 if(minElement==minK && maxElement==maxK)
                     count++;
            }
        }
        return count;
    }
    
    long long slidingWindow(vector<int>& nums, int minK, int maxK, int n)
    {
        long long count=0;
        int maxPos=-1, minPos=-1, culpritPos=-1;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]<minK || nums[i]>maxK)
                culpritPos = i;
            if(nums[i] == maxK)
                maxPos = i;
            if(nums[i] == minK)
                minPos = i;
            
            int smallerIndex = min(minPos, maxPos);
            int temp = smallerIndex - culpritPos;
            
            count += temp>0 ? temp : 0;
        }
        return count;
    }
    
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        
        // return bruteForce(nums, minK, maxK, n);
        
        return slidingWindow(nums, minK, maxK, n);
    }
};
class Solution {
private:
    int bruteForce(vector<int>& nums, int n)
    {
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++)
            if(nums[i] == nums[i+1])
                return nums[i];
        return -1;
    }
    int hashMap(vector<int>& nums, int n)
    {
        unordered_map<int, int> freq;
        
        for(int num:nums)
        {
            freq[num]++;
            if(freq[num] > 1)
                return num;
        }
        return 0;
    }
    int tortoiseAndHare(vector<int>& nums, int n)
    {
        int tortoise = nums[0];
        int hare = nums[0];
    
        // Phase 1: Detect if there's a cycle (find first meet point)
       do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while(tortoise != hare);
        // Phase 2: Find the start of the cycle
        // Distance from first node to starting of the cycle and first meet node to start node will be same
        tortoise = nums[0];
        while(tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
    
        
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // return bruteForce(nums, n);
        
        return hashMap(nums, n);
        
        // return tortoiseAndHare(nums, n);
        
    }
};
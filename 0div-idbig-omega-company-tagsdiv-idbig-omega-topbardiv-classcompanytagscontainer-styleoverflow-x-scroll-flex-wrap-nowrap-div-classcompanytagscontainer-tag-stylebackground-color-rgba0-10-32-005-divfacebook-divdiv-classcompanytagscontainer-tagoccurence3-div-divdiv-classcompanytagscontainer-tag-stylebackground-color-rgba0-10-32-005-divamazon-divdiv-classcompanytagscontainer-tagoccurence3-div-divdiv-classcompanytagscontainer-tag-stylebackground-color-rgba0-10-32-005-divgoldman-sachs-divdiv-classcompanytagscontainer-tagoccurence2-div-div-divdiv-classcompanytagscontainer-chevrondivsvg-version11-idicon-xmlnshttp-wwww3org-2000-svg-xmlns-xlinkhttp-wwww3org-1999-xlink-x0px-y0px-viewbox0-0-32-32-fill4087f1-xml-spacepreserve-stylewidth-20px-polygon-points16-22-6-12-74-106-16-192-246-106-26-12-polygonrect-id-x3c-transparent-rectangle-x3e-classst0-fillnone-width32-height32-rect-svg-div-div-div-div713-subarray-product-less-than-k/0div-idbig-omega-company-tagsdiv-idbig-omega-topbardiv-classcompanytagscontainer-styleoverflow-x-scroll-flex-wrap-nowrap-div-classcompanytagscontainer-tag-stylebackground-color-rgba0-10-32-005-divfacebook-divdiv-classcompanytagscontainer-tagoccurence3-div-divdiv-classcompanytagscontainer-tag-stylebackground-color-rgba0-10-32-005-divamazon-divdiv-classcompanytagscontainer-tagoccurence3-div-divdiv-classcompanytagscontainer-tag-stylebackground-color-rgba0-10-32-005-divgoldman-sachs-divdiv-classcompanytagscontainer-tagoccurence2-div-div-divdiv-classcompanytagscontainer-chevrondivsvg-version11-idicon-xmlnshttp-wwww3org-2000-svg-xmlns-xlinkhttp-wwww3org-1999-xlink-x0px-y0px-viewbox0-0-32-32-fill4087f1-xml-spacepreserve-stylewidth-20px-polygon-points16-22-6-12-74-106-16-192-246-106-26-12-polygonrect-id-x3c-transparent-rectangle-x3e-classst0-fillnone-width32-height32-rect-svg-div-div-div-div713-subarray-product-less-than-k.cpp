class Solution {
private:
    int bruteForce(vector<int>& nums, int k, int n)
    {
        int count=0;
        for(int i=0; i<n; i++)
        {
            int product = 1;
            for(int j=i; j<n; j++)
            {
                product *= nums[j];
                if(product < k)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
    
    int twoPointer(vector<int>& nums, int k, int n)
    {
        int front=0, back=0;
        int count=0, product=1;
        
        while(front<n)
        {
            product *= nums[front];
            
            while(product >= k)
                product /= nums[back++];
            
            count += front-back+1;
            front++;
                
        }
        return count;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1)
            return 0;
        int n = nums.size();

        // return bruteForce(nums, k, n);
        
        return twoPointer(nums, k, n);
    }
};
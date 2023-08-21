class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long XOR = nums[0];
        
        for(int i=1; i<n; i++)
            XOR = XOR^ 1LL*nums[i];
        
        long long rightmostSetBit = XOR & ~(XOR-1);
        int n1=0, n2=0;
        
        for(int i=0; i<n; i++)
            if(rightmostSetBit & 1LL*nums[i])
                n1 = n1^nums[i];
            else
                n2 = n2^nums[i];
        
        return {n1, n2};
    }
};
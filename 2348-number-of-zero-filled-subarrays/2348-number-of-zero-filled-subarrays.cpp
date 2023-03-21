class Solution {
public:

    long long zeroFilledSubarray(vector<int>& nums) {
        long long zero=0, ans=0;
        for(auto i : nums)
        {
            if(i==0)
                zero++;
            else
            {
                ans += zero*(zero+1)/2;
                zero = 0;
            }
        }
        if(zero)
            ans += zero*(zero+1)/2;
        return ans;
    }
};
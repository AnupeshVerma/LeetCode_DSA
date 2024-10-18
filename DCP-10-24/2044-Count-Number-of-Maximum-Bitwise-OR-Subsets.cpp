class Solution {
private:
    int countSubsets(vector<int>& nums, int index, int current_or, int max_or) {
        if(nums.size() == index)
            return current_or == max_or ? 1 : 0;
        
        int not_include = countSubsets(nums, index+1, current_or, max_or);
        int include = countSubsets(nums, index+1, current_or|nums[index], max_or);
        
        return include + not_include;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(int num : nums)
            max_or |= num;
        
        return countSubsets(nums, 0, 0, max_or);
    }
};
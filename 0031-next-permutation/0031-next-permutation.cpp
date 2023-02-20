class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    // USing C++ STL
    //next_permutation(nums.begin(), nums.end());

    int ind =-1;

    for(int i=nums.size()-2; i>=0; i--)
        if(nums[i+1] > nums[i])
        {
            ind = i;
            break;
        }

     for(int i=nums.size()-1; i>=ind && ind!=-1; i--)
    {
        if(nums[i] > nums[ind])
        {
           swap(nums[i], nums[ind]);
           break;
        }

    }
        reverse(nums.begin()+ind+1, nums.end());
        
            
    }
};
class Solution {
private:
    vector<int> bruteForce(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int>st, ansSet;
        
        for(auto num:nums1)
            st.insert(num);
        
        for(auto num:nums2)
            if(st.find(num) != st.end())
                ansSet.insert(num);
        
        vector<int>ans(ansSet.begin(), ansSet.end());
        return ans;
    }
    
    vector<int>twoPointer(vector<int>&nums1, vector<int>&nums2)
    {
        int n1=nums1.size(), n2=nums2.size();
        unordered_set<int>ansSet;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i=0, j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]==nums2[j])
            {
                ansSet.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        vector<int>ans(ansSet.begin(), ansSet.end());
        return ans;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        
        // return bruteForce(nums1, nums2);
        
        return twoPointer(nums1, nums2);
    }
};
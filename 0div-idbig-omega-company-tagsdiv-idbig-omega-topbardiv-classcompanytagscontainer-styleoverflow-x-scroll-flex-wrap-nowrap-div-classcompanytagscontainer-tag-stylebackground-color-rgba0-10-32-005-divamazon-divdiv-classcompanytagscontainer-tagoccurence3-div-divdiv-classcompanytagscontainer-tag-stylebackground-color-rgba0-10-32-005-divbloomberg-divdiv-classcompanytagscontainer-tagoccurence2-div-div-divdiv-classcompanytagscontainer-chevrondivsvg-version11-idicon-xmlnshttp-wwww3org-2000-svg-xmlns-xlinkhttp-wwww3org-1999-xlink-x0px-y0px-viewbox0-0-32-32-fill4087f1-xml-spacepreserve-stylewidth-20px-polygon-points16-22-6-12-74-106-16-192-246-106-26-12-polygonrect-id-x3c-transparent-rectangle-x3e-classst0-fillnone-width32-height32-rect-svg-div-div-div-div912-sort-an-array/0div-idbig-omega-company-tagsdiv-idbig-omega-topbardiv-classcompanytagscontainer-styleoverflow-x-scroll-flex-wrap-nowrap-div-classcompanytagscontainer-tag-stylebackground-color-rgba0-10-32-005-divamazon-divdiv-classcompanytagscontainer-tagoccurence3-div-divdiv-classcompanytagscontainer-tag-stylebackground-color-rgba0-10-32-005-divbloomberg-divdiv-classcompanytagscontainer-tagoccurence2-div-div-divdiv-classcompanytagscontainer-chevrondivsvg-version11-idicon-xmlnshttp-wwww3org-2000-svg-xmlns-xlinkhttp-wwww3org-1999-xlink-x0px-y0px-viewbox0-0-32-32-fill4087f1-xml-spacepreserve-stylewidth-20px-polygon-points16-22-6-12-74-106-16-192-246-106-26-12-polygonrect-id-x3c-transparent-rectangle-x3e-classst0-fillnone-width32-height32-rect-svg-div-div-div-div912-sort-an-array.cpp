class Solution {
private:
    vector<int> bubbleSort(vector<int>& nums, int n)
    {
        for(int i=0; i<n-1; i++)
        {
            bool swapped = false;   
            for(int j=0; j<n-1-i; j++)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            if(swapped == false)
                    break;
        }
        return nums;
    }
    
    vector<int> insertionSort(vector<int>& nums, int n)
    {
        for(int i=0; i<n; i++)
            for(int j=i; j>0; j--)
                if(nums[j-1] > nums[j])
                    swap(nums[j-1], nums[j]);
                else
                    break;
        return nums;
    }
    
    // Find the minimim in the unsorted part and give its poistion
    vector<int> selectionSort(vector<int>& nums, int n)
    {
        for(int i=0; i<n; i++)
        {
            int minInd=i;
            for(int j=i+1; j<n; j++)
            {
                nums[minInd]>nums[j] ? minInd=j : 0;
            }
            swap(nums[minInd], nums[i]);
        }
        return nums;
    }
    
    void quickSort(vector<int>& nums, int start, int end)
    {
        if(start >= end)
            return;
        
        int pivot = nums[end];
        int i=start;
        for(int j=start; j<=end; j++)
        {
            if(nums[j] < pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[end]);
        int pivotIndex = i;
        
        quickSort(nums, start, pivotIndex-1);
        quickSort(nums, pivotIndex+1, end);
        
    }
    
    void mergeSort(vector<int>nums, int start, int end)
    {
        if(start >= end)
            return;
        
        int mid = start + (start-end)/2;
        
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        
        // code for merging 
        
    }
    
     vector<int> sorting(vector<int>& nums) {
        vector<int> res;
        vector<int> freq(2 * 50000 + 1, 0);
        for (int& i : nums) {
            freq[i + 50000]++;
        }
        int it = 0;
        while (it < freq.size()) {
            if (freq[it] == 0) {
                it++;
                continue;
            }
            res.push_back(it - 50000);
            freq[it]--;
        }
        return res;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        
        // return bubbleSort(nums, n);
        
        // return insertionSort(nums, n);
        
        // return selectionSort(nums, n);
        
        // quickSort(nums, 0, n-1);
        
        // mergeSort(nums, 0, n-1);
        
        return sorting(nums);
        return nums;
    }
};
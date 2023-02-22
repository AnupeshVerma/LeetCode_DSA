class Solution {
public:
    //Function for checking number of days required for each mid
    int getdays(vector<int>weights, int mid)
    {
        int dayz = 1, size = weights.size();
        int sum = 0;
        
        for(int i=0; i<size; i++)
        {
           int s = weights[i];
            if(sum+s <= mid)
                sum+=s;
            else{
                dayz++;
                sum = s;
            }
            
        }
        return dayz;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int min_capacity = INT_MIN;
        int max_capacity = 0;
        int actual_capacity = 0;
        int ans;
        
        for(auto i : weights)
        {
            max_capacity+=i;
            min_capacity = max(min_capacity, i);
        }
        
        int low = min_capacity;
        int high = max_capacity;
        int mid = actual_capacity;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            
            // Check if required days for this mid are more then reduce the actual_capacity/mid
            int days_for_mid = getdays(weights, mid);
            if(days_for_mid <= days)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
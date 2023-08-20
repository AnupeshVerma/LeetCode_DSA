class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans;
        int n = arr.size();
        ans.push_back(-1);
        int leader = arr[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            ans.push_back(leader);
            if(arr[i] > leader)
                leader = arr[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
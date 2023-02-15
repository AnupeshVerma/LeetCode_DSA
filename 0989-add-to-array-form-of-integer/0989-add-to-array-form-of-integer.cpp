class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size()-1;
        vector<int> ans;

        for(int i=n; i>=0; i--)
        {
            int new_num = num[i]+k;
            ans.push_back(new_num%10);
            k = new_num/10;
        }
        while(k)
        {
            ans.push_back(k%10);
            k/=10;
        }
            
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
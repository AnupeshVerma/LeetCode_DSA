class Solution {
private:
    bool usingSet(vector<int>& arr, int n) {
        unordered_set<int> st;

        for(auto num : arr) {
            if(st.count(2*num) || (st.count(num/2) && num%2==0))
                return true;
            st.insert(num);
        }
        
        return false;
    }


public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        return usingSet(arr, n);
    }
};
class Solution {
public:
    int help(vector<string>& arr, int i, string temp){
        if(i >= arr.size())
            return 0;
        
        string newTemp = temp;
        for(char c : arr[i]){
            if(find(temp.begin(), temp.end(), c) != temp.end() || (find(newTemp.begin(), newTemp.end(), c) != newTemp.end())){
                return help(arr, i+1, temp);
            }
            newTemp += c;
        }
        int withCurrent = arr[i].size() + help(arr, i+1, newTemp);
        int withoutCurrent = help(arr, i+1, temp);
        
        return max(withCurrent, withoutCurrent);
    }
    int maxLength(vector<string>& arr) {
        return help(arr, 0, "");
    }
};
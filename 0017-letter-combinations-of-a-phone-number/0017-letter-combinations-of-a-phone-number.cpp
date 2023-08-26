class Solution {
private:
    vector<string>ans;
    string temp = "";
    void solve(string digits, unordered_map<char, string>&mp, int ind)
    {
        if(ind >= digits.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<mp[digits[ind]].size(); i++)
        {
            string key = mp[digits[ind]];
            temp += key[i];
            solve(digits, mp, ind+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        unordered_map<char, string>mp = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
        
        solve(digits, mp, 0);
        return ans;
    }
};
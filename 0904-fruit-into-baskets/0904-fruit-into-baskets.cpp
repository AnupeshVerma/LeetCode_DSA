class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int front=0, back=0, ans=0;
        
        while(front < fruits.size())
        {
            mp[fruits[front]]++;
            
            if(mp.size() <= 2)
                ans = max(ans, front-back+1);
            else
            {
                mp[fruits[back]]--;
                if(mp[fruits[back]] == 0)
                    mp.erase(fruits[back]);
                back++;
            }
            front++;
        }
        return ans;
    }
};
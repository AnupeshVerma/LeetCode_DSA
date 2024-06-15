class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         unordered_map<int, pair<int, int>>mp;
        
//         for(int i=0; i<capital.size(); i++)
//             mp.insert({i, make_pair(profits[i], capital[i])});
        
//         while(k--)
//         {
//             int max_profit = 0;
//             int delete_id;
//             for(auto i:mp)
//                 if(w >= i.second.second)
//                 {
                   
//                     if(i.second.first > max_profit)
//                     {
//                         max_profit = i.second.first;
//                         delete_id = i.first;
//                     }
//                 }
   
//             w += max_profit;
//            mp.erase(delete_id);
//         }
//         return w;
    int n = profits.size();
    vector<pair<int, int>> project(n);

    for (int i = 0; i < n; i++)
    {
        project[i] = {capital[i], profits[i]};
    }
    sort(project.begin(), project.end());
    priority_queue<int> pq;
    int i = 0;
    while (k--)
    {
        while (i < n and project[i].first <= w)
        {
            pq.push(project[i].second);
            i++;
        }
        if (pq.empty())
            break;

        w += pq.top();
        pq.pop();
    }
    return w;

    }
};
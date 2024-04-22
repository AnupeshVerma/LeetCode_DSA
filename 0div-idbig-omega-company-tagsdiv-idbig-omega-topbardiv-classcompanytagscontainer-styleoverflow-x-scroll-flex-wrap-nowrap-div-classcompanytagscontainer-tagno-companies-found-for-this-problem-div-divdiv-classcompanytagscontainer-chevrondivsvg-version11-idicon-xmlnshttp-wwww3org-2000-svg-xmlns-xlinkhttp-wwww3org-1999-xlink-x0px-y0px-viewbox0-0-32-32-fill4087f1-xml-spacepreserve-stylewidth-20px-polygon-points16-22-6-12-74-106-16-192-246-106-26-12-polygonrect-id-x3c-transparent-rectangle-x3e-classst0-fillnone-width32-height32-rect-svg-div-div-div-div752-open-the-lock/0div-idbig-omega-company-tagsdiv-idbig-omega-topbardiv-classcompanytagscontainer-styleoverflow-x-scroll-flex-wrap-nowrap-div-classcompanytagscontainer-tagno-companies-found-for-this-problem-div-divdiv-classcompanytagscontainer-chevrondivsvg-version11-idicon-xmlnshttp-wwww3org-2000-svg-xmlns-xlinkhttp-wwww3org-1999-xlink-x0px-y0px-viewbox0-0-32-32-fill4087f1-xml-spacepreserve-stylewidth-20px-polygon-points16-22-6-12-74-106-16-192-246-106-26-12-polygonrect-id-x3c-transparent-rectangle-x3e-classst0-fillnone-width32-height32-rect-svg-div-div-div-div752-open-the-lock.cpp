class Solution {
private:
    int bfs( vector<string>& deadends, string target)
    {
        unordered_set<string> st(begin(deadends), end(deadends));
        
        string start = "0000";
        if(st.find(start) != st.end())
            return -1;
        
        int level = 0;
        queue<string>q;
        q.push(start);
        
        while(!q.empty())
        {
            int n = q.size();   // Size of current level
            while(n--)
            {
                string curr = q.front();
                q.pop();
                
                if(curr == target)
                    return level;
                
                for(int i=0; i<4; i++)
                {
                    char ch = curr[i];
                    
                    char inc = ch=='9' ? '0' : ch+1;
                    char dec = ch=='0' ? '9' : ch-1;
                    
                    curr[i] = inc;
                    if(st.find(curr) == st.end()) st.insert(curr), q.push(curr);
                    
                    curr[i] = dec;
                    if(st.find(curr) == st.end()) st.insert(curr), q.push(curr);
                    
                    curr[i] = ch;
                }
            }
            level++;
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        
        return bfs(deadends, target);
    }
};
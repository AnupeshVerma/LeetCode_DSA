class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>>& board, string &word, int idx, vector<vector<bool>> &vis)
    {
        if(idx == word.size()) return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j])
        {
            return false;
        }

        if(board[i][j] != word[idx])
        {
            return false;
        }

        vis[i][j] = true;
        bool up = dfs(i - 1, j, board, word, idx + 1, vis);
        bool down = dfs(i + 1, j, board, word, idx + 1, vis);
        bool right = dfs(i, j + 1, board, word, idx + 1, vis);
        bool left = dfs(i, j - 1, board, word, idx + 1, vis);
        vis[i][j] = false;

        return (up | down | right | left);
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++)
        {
            bool ret = false;
            for(int j = 0; j < m; j++)
            {
                ret = dfs(i, j, board, word, 0, vis);

                if(ret) return true;
            }
        }

        return false;
    }
};
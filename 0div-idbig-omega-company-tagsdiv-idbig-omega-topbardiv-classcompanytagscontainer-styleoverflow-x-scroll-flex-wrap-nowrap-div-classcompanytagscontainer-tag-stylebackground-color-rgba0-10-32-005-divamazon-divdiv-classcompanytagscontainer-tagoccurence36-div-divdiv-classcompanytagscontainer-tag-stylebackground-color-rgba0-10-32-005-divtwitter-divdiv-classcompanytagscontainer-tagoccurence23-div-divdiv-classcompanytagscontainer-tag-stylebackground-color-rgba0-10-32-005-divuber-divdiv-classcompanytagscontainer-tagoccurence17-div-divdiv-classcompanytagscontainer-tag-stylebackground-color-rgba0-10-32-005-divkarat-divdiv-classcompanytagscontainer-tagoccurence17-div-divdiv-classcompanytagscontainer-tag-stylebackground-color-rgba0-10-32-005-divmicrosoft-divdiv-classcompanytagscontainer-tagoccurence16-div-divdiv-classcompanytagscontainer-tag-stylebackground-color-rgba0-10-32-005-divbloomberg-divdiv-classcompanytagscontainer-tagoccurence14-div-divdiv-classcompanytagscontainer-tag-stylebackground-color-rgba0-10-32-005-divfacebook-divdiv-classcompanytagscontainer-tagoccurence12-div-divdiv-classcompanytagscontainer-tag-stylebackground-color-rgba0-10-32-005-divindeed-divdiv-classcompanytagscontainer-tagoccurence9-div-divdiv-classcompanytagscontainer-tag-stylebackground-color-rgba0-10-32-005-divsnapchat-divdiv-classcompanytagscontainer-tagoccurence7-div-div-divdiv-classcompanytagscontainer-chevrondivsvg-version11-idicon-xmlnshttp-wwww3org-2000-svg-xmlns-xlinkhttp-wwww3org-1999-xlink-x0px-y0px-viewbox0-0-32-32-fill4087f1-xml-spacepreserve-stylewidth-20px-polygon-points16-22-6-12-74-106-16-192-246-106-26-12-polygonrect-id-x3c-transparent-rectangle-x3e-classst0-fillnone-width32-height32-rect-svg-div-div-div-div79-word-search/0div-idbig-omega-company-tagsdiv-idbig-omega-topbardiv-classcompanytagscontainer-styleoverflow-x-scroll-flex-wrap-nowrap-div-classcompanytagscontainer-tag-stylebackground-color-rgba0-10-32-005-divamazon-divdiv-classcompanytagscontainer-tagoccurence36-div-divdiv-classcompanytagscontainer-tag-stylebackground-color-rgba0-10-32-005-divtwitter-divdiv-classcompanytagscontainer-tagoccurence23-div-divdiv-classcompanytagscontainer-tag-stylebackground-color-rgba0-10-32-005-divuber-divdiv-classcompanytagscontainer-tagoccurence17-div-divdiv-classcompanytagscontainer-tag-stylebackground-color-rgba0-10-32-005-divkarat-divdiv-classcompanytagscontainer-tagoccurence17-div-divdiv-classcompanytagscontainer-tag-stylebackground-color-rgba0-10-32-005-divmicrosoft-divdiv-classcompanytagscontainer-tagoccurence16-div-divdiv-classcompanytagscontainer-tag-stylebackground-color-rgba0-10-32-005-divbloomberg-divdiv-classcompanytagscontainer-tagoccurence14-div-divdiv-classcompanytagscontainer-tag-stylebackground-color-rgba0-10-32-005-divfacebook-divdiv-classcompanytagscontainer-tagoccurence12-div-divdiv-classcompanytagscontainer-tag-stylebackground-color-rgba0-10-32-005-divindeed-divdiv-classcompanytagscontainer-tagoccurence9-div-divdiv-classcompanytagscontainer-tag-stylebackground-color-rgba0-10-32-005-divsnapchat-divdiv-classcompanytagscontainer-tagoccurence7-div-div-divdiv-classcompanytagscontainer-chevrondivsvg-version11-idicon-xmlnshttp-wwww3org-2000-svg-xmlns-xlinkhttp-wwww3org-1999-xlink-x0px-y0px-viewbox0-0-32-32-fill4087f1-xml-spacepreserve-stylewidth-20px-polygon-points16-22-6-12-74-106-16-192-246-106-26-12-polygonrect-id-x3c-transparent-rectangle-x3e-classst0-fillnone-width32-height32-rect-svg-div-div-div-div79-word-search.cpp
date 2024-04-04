class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int ind, int n)
    {   
        if(ind >= n)
            return true;
         if(row<0 || row>=board.size() || col<0 || col>=board[0].size())
            return false;
        
        char ch = board[row][col];
        if(ch != word[ind])
            return false;
        else
        {
            board[row][col] = '-';
            bool up    = dfs(board, word, row-1, col, ind+1, n);
            bool right = dfs(board, word, row, col+1, ind+1, n);
            bool down  = dfs(board, word, row+1, col, ind+1, n);
            bool left  = dfs(board, word, row, col-1, ind+1, n);
            
            board[row][col] = ch;
            return up || right || down || left;
        }
        
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int ans = false;
        for(int row=0; row<board.size(); row++)
            for(int col=0; col<board[0].size(); col++)
            {
                ans = ans || dfs(board, word, row, col, 0, word.size());
            }
        return ans;
    }
};
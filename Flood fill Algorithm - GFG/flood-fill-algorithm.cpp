//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<int>>& image, int row, int col, int newColor, int iniColor, vector<vector<int>>&ans)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol] == iniColor && ans[newRow][newCol]!=newColor)
                dfs(image, newRow, newCol, newColor, iniColor, ans);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> ans = image;
        
        int iniColor = image[sr][sc];
        
        // Traverse fron source to 4 directions
        dfs(image, sr, sc, newColor, iniColor, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
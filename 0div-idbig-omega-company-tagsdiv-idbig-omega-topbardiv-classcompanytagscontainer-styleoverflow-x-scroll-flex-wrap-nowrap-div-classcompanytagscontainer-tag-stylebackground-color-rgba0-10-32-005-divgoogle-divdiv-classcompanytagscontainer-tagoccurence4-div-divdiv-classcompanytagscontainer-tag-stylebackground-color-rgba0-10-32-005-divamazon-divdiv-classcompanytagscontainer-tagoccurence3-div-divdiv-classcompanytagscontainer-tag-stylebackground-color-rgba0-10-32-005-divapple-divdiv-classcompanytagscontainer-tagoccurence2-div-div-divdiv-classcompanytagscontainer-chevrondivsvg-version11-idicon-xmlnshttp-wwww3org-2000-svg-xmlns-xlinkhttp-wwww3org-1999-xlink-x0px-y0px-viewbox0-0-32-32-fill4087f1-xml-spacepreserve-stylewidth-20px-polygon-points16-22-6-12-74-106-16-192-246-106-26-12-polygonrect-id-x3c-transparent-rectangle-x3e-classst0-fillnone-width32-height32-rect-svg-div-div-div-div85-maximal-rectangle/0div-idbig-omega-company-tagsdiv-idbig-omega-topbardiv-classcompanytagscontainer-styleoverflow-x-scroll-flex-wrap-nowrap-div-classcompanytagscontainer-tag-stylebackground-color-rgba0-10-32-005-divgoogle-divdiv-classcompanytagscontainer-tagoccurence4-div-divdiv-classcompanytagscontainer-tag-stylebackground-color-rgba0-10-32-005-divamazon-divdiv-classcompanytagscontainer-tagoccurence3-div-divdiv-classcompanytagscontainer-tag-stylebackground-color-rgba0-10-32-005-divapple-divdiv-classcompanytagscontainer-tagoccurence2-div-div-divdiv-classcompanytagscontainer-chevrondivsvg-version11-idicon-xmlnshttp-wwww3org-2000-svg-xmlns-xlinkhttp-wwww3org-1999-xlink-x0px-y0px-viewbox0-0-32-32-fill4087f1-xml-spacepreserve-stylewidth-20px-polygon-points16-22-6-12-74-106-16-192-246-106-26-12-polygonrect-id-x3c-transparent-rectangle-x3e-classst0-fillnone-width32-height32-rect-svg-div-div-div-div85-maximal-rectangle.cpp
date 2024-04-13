class Solution {
public:
        int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int maxA=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int h=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else{
                    width=i-st.top()-1;
                }
                maxA=max(maxA,width*h);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        int p=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        for(int i=0;i<p;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            int area=largestRectangleArea(heights);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};
class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int i=0;
        int maxi = 0;

        while(i<n){
            if(st.empty() || heights[i]>=heights[st.top()]){
                st.push(i);
                i++;
            }else{
                auto t = st.top();
                st.pop();

                int w = st.empty()?i:i-st.top()-1;
                int area = heights[t]*w;
                maxi = max(maxi, area);
            }
        }

        while(!st.empty()){
            auto t = st.top();
            st.pop();

            int w = st.empty()?i:i-st.top()-1;
            int area = heights[t]*w;
            maxi = max(maxi, area);
        }

        return maxi;
    }
    
    int maxArea(vector<vector<int>> &matrix) {
        // code here
        int m = matrix[0].size();
        int n = matrix.size();

        vector<int> ht(m, 0);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    ht[j]++;
                }else{
                    ht[j]=0;
                }
                //cout << ht[j] << ' ';
            }
            //cout << endl;

            maxi = max(maxi, largestRectangleArea(ht));
        }

        return maxi;
    }
};
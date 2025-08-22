class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        priority_queue<int> maxh; // left half
        priority_queue<int, vector<int>, greater<int>> minh; // right half
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = mat[i][j];
                
                if(maxh.empty()) {
                    maxh.push(x);
                }
                else if(x <= maxh.top()){
                    maxh.push(x);
                }
                else{
                    minh.push(x);
                }
                
                if(maxh.size() > minh.size() + 1){
                    minh.push(maxh.top());
                    maxh.pop();
                }
                else if(minh.size() > maxh.size()){
                    maxh.push(minh.top());
                    minh.pop();
                }
            }
        }
        
        
        return maxh.top(); 
    }
};

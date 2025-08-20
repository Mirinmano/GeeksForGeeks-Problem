class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> suf(n);
        suf[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = min(suf[i+1], arr[i]);
        }
        
        
        vector<int> res(n, -1);
        res.push_back(-1);
        for(int i=0;i<n-1;i++){
            int l = i+1;
            int r = n-1;
            int mid;
            int ans = -1;
            
            while(l<=r){
                mid = l+(r-l)/2;
                if(suf[mid]<arr[i]){
                    ans = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            
            if(ans!=-1){
                res[i] = ans;
            }
        }
        
        return res;
    }
};
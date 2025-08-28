class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int z = 0, ans = 0;
        
        while(i<n){
            if(arr[i]==0) z++;
            
            while(z>k){
                if(arr[j++]==0) z--;
            }
            
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};

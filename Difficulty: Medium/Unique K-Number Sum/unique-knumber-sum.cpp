class Solution {
  public:
     void solve(vector<vector<int>>&ans,vector<int>&t,int s,int i,int k,int sum){
        if(i==k){
            if(sum==s)ans.push_back(t);
            return;
        }
        int j = 1;
        for(j=max(1,t[i-1]+1);j<10;j++){
            t[i]=j;
            sum+=j;
            solve(ans,t,s,i+1,k,sum);
            sum-=j;
        }
        
    }
  
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        
        vector<int>t(k,0);
        int sum=0;
        solve(ans,t,n,0,k,sum);
        
        return ans;
    }
};
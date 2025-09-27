class Solution {
  public:
     int solve(int i,vector<vector<int>>&dp,int sum,vector<int>&coins,int n){
      if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
      if(sum==0){
          return 1;
      }
      if (i >= n){
          return 0;
      }  
      int take=0;
      int nottake=0;
      if(sum>=coins[i]){
          take=solve(i,dp,sum-coins[i],coins,n);
      }
      nottake=solve(i+1,dp,sum,coins,n);
      return dp[i][sum]=take+nottake;
  }
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,dp,sum,coins,n);
    }
};
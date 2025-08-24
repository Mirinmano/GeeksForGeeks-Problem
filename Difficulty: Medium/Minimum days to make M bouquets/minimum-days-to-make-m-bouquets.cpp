class Solution {
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        if(n < (m*k)){
            return -1;
        }
        sort(arr.begin(), arr.end());
        return arr[(m*k) - 1];
    }
};
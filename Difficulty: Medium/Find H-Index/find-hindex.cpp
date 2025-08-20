class Solution {
  public:
    int hIndex(vector<int>& a) {
        // code here
        sort(a.rbegin(), a.rend());
        int n = a.size();
        if (n == 1){
            if (a[0] == 0) return 0;
            return 1;
        }
        for (int i = 0; i < n; i++){
            if (a[i]<=i) return i;
        }
        return n;
    }
};
class Solution {
  public:
    bool helper(vector<int> &arr, int maxi, int k) {
        int cnt = 1; 
        int temp = 0;
        
        for (int x : arr) {
            if (temp + x > maxi) {
                cnt++;
                temp = x;
            } else {
                temp += x;
            }
            if (cnt > k) return false; 
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; 
        
        int l = *max_element(arr.begin(), arr.end()); 
        int h = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (helper(arr, mid, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
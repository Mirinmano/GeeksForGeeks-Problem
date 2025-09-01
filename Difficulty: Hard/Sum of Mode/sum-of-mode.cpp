class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        map<int, set<int>, greater<int>> mode; 

        int res = 0, n = arr.size();
        for(int i = 0; i < k; i++) {
            int oldFreq = freq[arr[i]];
            if(oldFreq > 0) {
                mode[oldFreq].erase(arr[i]);
                if(mode[oldFreq].empty()) mode.erase(oldFreq);
            }
            freq[arr[i]]++;
            mode[freq[arr[i]]].insert(arr[i]);
        }
        res += *(mode.begin()->second.begin());

        for(int i = k; i < n; i++) {
            int out = arr[i-k];
            int oldFreq = freq[out];
            mode[oldFreq].erase(out);
            if(mode[oldFreq].empty()) mode.erase(oldFreq);
            freq[out]--;
            if(freq[out] > 0) {
                mode[freq[out]].insert(out);
            }

            int in = arr[i];
            oldFreq = freq[in];
            if(oldFreq > 0) {
                mode[oldFreq].erase(in);
                if(mode[oldFreq].empty()) mode.erase(oldFreq);
            }
            freq[in]++;
            mode[freq[in]].insert(in);

            res += *(mode.begin()->second.begin());
        }

        return res;
    }
};

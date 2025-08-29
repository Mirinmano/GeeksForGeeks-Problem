class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        if (s.size() < p.size()) return "";

        // frequency of chars in p
        vector<int> freqP(256, 0);
        for (char c : p) freqP[c]++;

        // sliding window variables
        vector<int> freqS(256, 0);
        int start = 0, minLen = INT_MAX, minStart = -1;
        int required = p.size(); // total chars required
        int count = 0; // matched chars

        for (int end = 0; end < s.size(); end++) {
            char c = s[end];
            freqS[c]++;

            // if current char satisfies one requirement
            if (freqP[c] > 0 && freqS[c] <= freqP[c]) {
                count++;
            }

            // if window contains all chars of p
            while (count == required) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                // shrink window
                char left = s[start];
                freqS[left]--;
                if (freqP[left] > 0 && freqS[left] < freqP[left]) {
                    count--;
                }
                start++;
            }
        }

        return (minStart == -1) ? "" : s.substr(minStart, minLen);
    }
};
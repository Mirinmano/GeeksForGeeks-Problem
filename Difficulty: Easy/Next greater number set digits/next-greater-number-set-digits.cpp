
class Solution {
  public:
    int findNext(int N) {
        // code here.
        string s = to_string(N);
        next_permutation(s.begin(), s.end());
        auto t = stoll(s);
        return (t<=N)?-1:t;
    }
};
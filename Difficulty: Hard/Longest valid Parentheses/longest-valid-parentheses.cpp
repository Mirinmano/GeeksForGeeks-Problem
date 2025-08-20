
class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int> st;
        st.push(-1);
        int m = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    m = max(m, i - st.top());
                }
            }
        }
        return m; 
    }
};
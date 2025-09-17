class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> st;
        stack<int> nums;
        string currStr = "";
        int currNum = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                currNum = currNum * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                nums.push(currNum);
                st.push(currStr);
                currNum = 0;
                currStr = ""; 
            } else if (s[i] == ']') {
                string temp = currStr;
                int repeatCount = nums.top();
                nums.pop();
                
                currStr = st.top();
                st.pop();
                
                for (int j = 0; j < repeatCount; ++j) {
                    currStr += temp;
                }
            } else {
                currStr += s[i];
            }
        }
        
        return currStr;
    }
};
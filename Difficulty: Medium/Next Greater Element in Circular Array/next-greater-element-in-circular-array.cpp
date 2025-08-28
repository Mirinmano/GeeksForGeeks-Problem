class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &nums) {
        // code here
        stack<int> st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }

            st.push(nums[i]);
        }

        int t;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            
            if(!st.empty()){
                t = st.top();
            }else{
                t = -1;
            }
            st.push(nums[i]);
            nums[i] = t;
        }

        return nums;
    }
};
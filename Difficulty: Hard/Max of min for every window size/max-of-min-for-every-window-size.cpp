class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
         int n = arr.size();
        vector<int>nextsmaller(n,n);
        vector<int>prevsmaller(n,-1);
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) prevsmaller[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextsmaller[i] = st.top();
            }
            st.push(i);
        }
        vector<int>dif(n,0);
        for(int i = 0 ; i < n ; i++){
            dif[i]=nextsmaller[i]-prevsmaller[i]-1;
        }
        set<pair<int,int>,greater<pair<int,int>>>o;
        for(int i = 0 ; i < n ; i++){
            o.insert({arr[i],dif[i]});
        }
        vector<int>ans;
        for (int k = 1; k <= n; k++) {
        auto it = o.begin();
    
        while (it != o.end() && it->second < k) {
            it = o.erase(it);
            }
        
        if (!o.empty()) {
            ans.push_back(o.begin()->first);
            }
        }
            return ans;
    }
};
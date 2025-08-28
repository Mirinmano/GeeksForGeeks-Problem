class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        int i = 0, j = 0, k = 0;
        vector<int> res;
        
        while(i<n1 && j<n2 && k<n3){
            while(i+1<n1){
                if(arr1[i]!=arr1[i+1]) break;
                i++;
            }
            while(j+1<n2){
                if(arr2[j]!=arr2[j+1]) break;
                j++;
            }
            while(k+1<n3){
                if(arr3[k]!=arr3[k+1]) break;
                k++;
            }
            
            int t = max(arr1[i], max(arr2[j], arr3[k]));
            if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
                res.push_back(t);
                i++; j++; k++;
            }else{
                if(arr1[i]<t) i++;
                if(arr2[j]<t) j++;
                if(arr3[k]<t) k++;
            }
        }
        
        if(res.size()==0) return {-1};
        return res;
    }
};
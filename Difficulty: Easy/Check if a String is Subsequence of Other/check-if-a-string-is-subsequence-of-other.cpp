class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        int p1=0,p2=0;
        while(p1<n && p2<m){
            if(s1[p1]==s2[p2]) {
                p1++;
            }
            p2++;
        }
        if(p1!=n) return false;
        return true;
    }
};
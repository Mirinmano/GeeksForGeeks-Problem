#User function Template for python3

class Solution:
    def medianOf2(self, a, b):
        #code here
        l = a+b
        l.sort()
        if len(l)%2==0:
            i=len(l)//2
            return (l[i]+l[i-1])/2
        else :
            return l[len(l)//2]
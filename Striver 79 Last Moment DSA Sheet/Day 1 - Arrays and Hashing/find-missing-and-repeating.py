
# https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating

#User function Template for python3

class Solution:
    def findTwoElement(self, arr, n): 
        # code here
        a = n*(n+1)//2
        b = (n*(n+1)*(2*n+1))//6
        c = sum(arr)
        d = 0
        for ele in arr:
            d = d + ele*ele
        
        S = a - c
        T = b - d
        x = (S*S + T)/(2*S)
        y = T/S - x
        
        return [int(y), int(x)]
        

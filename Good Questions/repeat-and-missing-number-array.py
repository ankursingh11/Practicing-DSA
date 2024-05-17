
# https://www.interviewbit.com/problems/repeat-and-missing-number-array/

class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    
    '''
    X -> Repeating Number
    Y -> Missing Number
    
    X - Y = sum_of_array - (n*(n+1))/2 = S
    X^2 - Y^2 = sum_of_square_of_array_element - (n*(n+1)*(2*n+1))/6 = T
    '''
    
    def repeatedNumber(self, A):
        
        n = len(A)
        a = n*(n+1)//2
        b = (n*(n+1)*(2*n+1))//6
        c = sum(A)
        d = 0
        for ele in A:
            d = d + ele*ele
        
        S = a-c
        T = b-d
        x = (S*S + T)/(2*S)
        y = T/S - x
        
        return [int(y), int(x)]
        

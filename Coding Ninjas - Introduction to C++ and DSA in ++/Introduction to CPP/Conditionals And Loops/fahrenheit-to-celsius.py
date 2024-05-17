

# Read input as sepcified in the question
# Print output as specified in the question

s = int(input())
e = int(input())
w = int(input())

while s <= e :
    c = (5/9)*(s-32)
    print(s, " ", str(int(c)))
    s += w


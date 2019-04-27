catalannumbers = [0 for i in range(5001)] 
catalannumbers[0] = 1
for i in range(1 , 5001):
    catalannumbers[i] = 2 * (2 * i - 1) * catalannumbers[i - 1] // (i + 1)

t = int(input()) 
for i in range(t):
    n = int(input())
    print (catalannumbers[n])

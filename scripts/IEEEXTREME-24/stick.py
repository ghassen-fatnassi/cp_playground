n,k,l=input().split()
n=int(n)
k=int(k)
l=int(l)
if(k>2*l):
    print((2 * l) * (2 * l) * n )
else:
    print((2 * l) * (2 * l) * n - (n - 1) * (2 * l - k) * (2 * l - k))
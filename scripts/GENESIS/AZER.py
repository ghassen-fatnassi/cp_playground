import collections
import bisect
import sys
import math
input=sys.stdin.readline
def gcd(m,n):
    if n==0:
        return m 
    else:
        return gcd(n,m%n)
def Divsors(k):
    d=[]
    for i in range(1,int(math.sqrt(k))+1):
        if k%i==0: d.extend({i,k//i})
    return d 


n=int(input()) 
a=list(map(int,input().split()))
if n==1 or n==2:
    print(1)
    print(*[a.index(1)+1])   
else:
    p=collections.Counter(a)
    v=[]
    for i in range(n):
        v.append((a[i],i))
    v.sort()
    ans=[]
    for i in range(n):
        if p[v[i][0]]!=0:
            p[v[i][0]]=0
            ans.append(v[i][1]+1)
            if v[i][1]==n-1:
                p[a[n-2]]=0 
                a.pop(n-2)
            elif v[i][1]==0:
                p[a[1]]=0
                a.pop(1)
            else:
                p[a[v[i][1]-1]]=0 
                p[a[v[i][1]+1]]=0 
                a.pop(v[i][1]+1)
                a.pop(v[i][1]-1)
    print(len(ans))
    print(*ans)        



            


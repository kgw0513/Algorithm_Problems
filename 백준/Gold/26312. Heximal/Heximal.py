import math
N=int(input())
if(N==0):
    print(1)
    exit(0)
h=math.floor(math.log10(N)/math.log10(6))
while(6**(h+1)<=N) : h+=1
while(6**h>N) : h-=1
print(h+1)
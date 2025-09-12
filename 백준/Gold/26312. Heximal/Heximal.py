import math
N=int(input())
if(N==0) :N=1
h=math.floor(math.log(N,6))
while(6**(h+1)<=N) : h+=1
while(6**h>N) : h-=1
print(h+1)
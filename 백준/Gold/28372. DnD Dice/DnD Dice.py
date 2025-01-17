
from queue import PriorityQueue
que=PriorityQueue()
arr=[4,6,8,12,20]

dp=[0]*501
dp[0]=1

inputs=list(map(int,input().split()))

for i in range(5) :
    now_loop=inputs[i]
    for _ in range(0,now_loop) :
        save_dp=[0]*501
        for j in range(1,arr[i]+1):
            for k in range(500,j-1,-1):
                save_dp[k]+=dp[k-j]
        
        for j in range(0,501):
            dp[j]=save_dp[j]

for i in range(0,501):
    #print(i,":",dp[i])
    if dp[i] != 0 :
        que.put((-dp[i],i))

#print(que.qsize(),"개.")
while not que.empty() :
    print(que.get()[1],end=" ")
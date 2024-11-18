s=input()

ans=1
count=1

for a in s :
    if a=='P':
        continue
    if a=='L':
        ans*=2
        continue
    if a=='R':
        ans=ans*2+count
        continue
    ans=ans*5+count
    count*=3

print(ans)
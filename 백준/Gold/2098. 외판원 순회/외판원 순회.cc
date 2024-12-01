#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;
 
const int INF=2147483647;
const int nINF=1147483647;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<pii,int> pii_i;

int arr[17][1<<16];
int brr[17][17];
int dfs(int now_p,int now_state,const int &have_home){
    if(arr[now_p][now_state])return arr[now_p][now_state];
    if(now_state==0)return arr[now_p][now_state]=((brr[now_p][1]==0)?nINF:brr[now_p][1]);
    //cout<<now_p<<"가 "<<now_state<<"가지고 방문.\n";
    arr[now_p][now_state]=nINF;
    for(int i=1;i<=have_home;i++){
        if(brr[now_p][i]==0||(now_state&(1<<(i-1)))==0)continue;
        arr[now_p][now_state]=min(arr[now_p][now_state],dfs(i,now_state-(1<<(i-1)),have_home)+brr[now_p][i]);
    }
    //cout<<now_p<<"에 "<<now_state<<"잔량으로 :"<<arr[now_p][now_state]<<"\n";
    return arr[now_p][now_state];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>brr[i][j];
        }
    }
    cout<<dfs(1,(1<<n)-2,n);
}
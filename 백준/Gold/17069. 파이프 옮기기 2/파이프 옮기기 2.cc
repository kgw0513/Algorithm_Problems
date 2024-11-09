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
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;

const int INF=2147483647;
const int not_flow_INF=100000000;

typedef pair<int,int> intint;
typedef pair<intint,int> int2_int;
typedef long long ll;

ll x_pipe[33][33];// ㅡ
ll y_pipe[33][33];// ㅣ
ll xy_pipe[33][33];// \

bool cantgo[33][33];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    x_pipe[1][2]=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cin>>w;
           if(w==1){
               cantgo[i][j]=true;
           }
           if(i==1&&j<=2)continue;
           if(w==0){
               x_pipe[i][j]+=x_pipe[i][j-1]+xy_pipe[i][j-1];
               y_pipe[i][j]+=y_pipe[i-1][j]+xy_pipe[i-1][j];
               if(!cantgo[i-1][j]&&!cantgo[i][j-1])
               xy_pipe[i][j]+=x_pipe[i-1][j-1]+y_pipe[i-1][j-1]+xy_pipe[i-1][j-1];
           }
        }
    }

    cout<<xy_pipe[n][n]+x_pipe[n][n]+y_pipe[n][n];
}
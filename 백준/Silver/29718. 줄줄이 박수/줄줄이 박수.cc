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
const int nINF=10000000;
 
typedef long long ll;
typedef pair<int,int> intint;
typedef pair<int,ll> intlong;
typedef pair<intint,int> int2_int;
typedef pair<int,char> int_char;

int arr[2001][2001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,w;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>arr[i][j];
    
    int now_sum=0;
    cin>>w;
    for(int j=0;j<w;j++)
    for(int i=0;i<n;i++)now_sum+=arr[i][j];
    
    int now_max=now_sum;
    for(int j=w;j<m;j++){
        for(int i=0;i<n;i++){
            now_sum+=arr[i][j];
            now_sum-=arr[i][j-w];
        }
        now_max=max(now_max,now_sum);
    }
    cout<<now_max;
}
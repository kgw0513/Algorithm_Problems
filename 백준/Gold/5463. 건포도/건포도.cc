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
#include <utility>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

/*
pbds c++ set전용
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset을 쓰고 싶으면 위의 코드에서 마지막 줄만 아래 코드로 변경.(대신 erase가 정상작동 되지 않는다.)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

이외에 범위를 늘리고 싶으면 타입변경하면 된다.
ex. int->ll, less_equal<ll>
*/

//unordered_set, unordered_map 전용 (구조체로 쓸 경우 == operator도 필요)
//사용 예시 : unordered_set<intint,pair_hash> arr;
namespace std {
    struct default_hash {
        template <class T1>
        size_t operator()(const T1 n) const {
            hash<T1> a{}; size_t sa = a(n);
            return sa;
        }
    };
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> n) const {
            hash<T1> a{}; size_t sa = a(n.fi);
            hash<T2> b{}; size_t sb = b(n.se);
            return sa ^ sb;
        }
    };
}

constexpr double PI = 3.1415926535;
constexpr long long INF = 2147483647;
constexpr long long lINF = 9000000000000000000;
constexpr long long nlINF = lINF / 10000;
constexpr int nINF = 1007483647;
constexpr long long MOD1 = 1000000007;
constexpr long long MOD2 = 1000000009;
constexpr long long MOD3 = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<double, double> dd;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, intint> int_int2;
typedef pair<ll, ll_ll> ll_ll2;
typedef pair<ll_ll, ll>ll2_ll;
typedef pair<intint, intint> int2_int2;
typedef pair<ll_ll, ll_ll> ll2_ll2;
typedef pair<char, int> char_int;
typedef pair<int, char> int_char;
typedef complex<double> cpx;

ll inputs[51][51];
ll sum[51][51];
ll dp[51][51][51][51];
ll cal(intint s,intint e){
	if(s.fi>e.fi || s.se>e.se)return 0;
	if(dp[s.fi][s.se][e.fi][e.se]!=0){
		return dp[s.fi][s.se][e.fi][e.se];
	}
	if(s==e){
		return 0;
	}
	dp[s.fi][s.se][e.fi][e.se]=lINF;
	for(int x=s.fi;x<e.fi;x++){
		dp[s.fi][s.se][e.fi][e.se]=min(dp[s.fi][s.se][e.fi][e.se],cal(s,{x,e.se})+cal({x+1,s.se},e));
	}
	for(int y=s.se;y<e.se;y++){
		dp[s.fi][s.se][e.fi][e.se]=min(dp[s.fi][s.se][e.fi][e.se],cal(s,{e.fi,y})+cal({s.fi,y+1},e));
	}
	dp[s.fi][s.se][e.fi][e.se]+=sum[e.fi][e.se]-sum[e.fi][s.se-1]-sum[s.fi-1][e.se]+sum[s.fi-1][s.se-1];
	return dp[s.fi][s.se][e.fi][e.se];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>inputs[i][j];
    		sum[i][j]=inputs[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    	}
    }
    cout<<cal({1,1},{n,m});
}
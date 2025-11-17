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
#include <cassert>
#pragma warning(disable:4996)
#define fi first
#define se second
#define print_end "\n"
using namespace std;
/*
rope c++
#include <ext/rope>
using namespace __gnu_cxx;
*/

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

//[4가지 방향][s][e]
ll dp[4][500][500];
ll dp2[4][500][500];

ll ccw(ll_ll a, ll_ll b, ll_ll c) {
    return (a.fi * b.se + b.fi * c.se + c.fi * a.se) - (a.se * b.fi + b.se * c.fi + c.se * a.fi);
}

ll2_ll Nodes[502];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 500; j++) {
            for (int k = 0; k < 500; k++) {
                dp2[i][j][k] = INF;
            }
        }
    }
    //cout << ccw({ 1,1 }, { 2,2 }, { 1,2 });
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> Nodes[i].fi.fi >> Nodes[i].fi.se >> Nodes[i].se;
        sum += Nodes[i].se;
    }
    
    //0번째 왼위
    for (int i = 1; i < n; i++) { //왼
        for (int j = 1; j < n; j++) {//위
            for (int p = 0; p < m; p++) {
                ll h = ccw({ 0,i }, { j,n }, Nodes[p].fi);
                if (h > 0) {
                    dp[0][i][j] += Nodes[p].se;
                }
            }
        }
    }

    //1번째 위오
    for (int i = 1; i < n; i++) { //위
        for (int j = 1; j < n; j++) {//오
            for (int p = 0; p < m; p++) {
                ll h = ccw({ i,n }, { n,j }, Nodes[p].fi);
                if (h > 0) {
                    dp[1][i][j] += Nodes[p].se;
                }
            }
        }
    }

    //2번째 오아
    for (int i = 1; i < n; i++) { //오
        for (int j = 1; j < n; j++) {//아
            for (int p = 0; p < m; p++) {
                ll h = ccw({ n,i }, { j,0 }, Nodes[p].fi);
                if (h > 0) {
                    dp[2][i][j] += Nodes[p].se;
                }
            }
        }
    }

    //3번째 오아
    for (int i = 1; i < n; i++) { //아
        for (int j = 1; j < n; j++) {//왼
            for (int p = 0; p < m; p++) {
                ll h = ccw({ i,0 }, { 0,j }, Nodes[p].fi);
                if (h > 0) {
                    dp[3][i][j] += Nodes[p].se;
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp2[0][i][j] = dp[0][i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k < n; k++) {
                dp2[1][i][k] = min(dp2[1][i][k],dp2[0][i][j] + dp[1][j][k]);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k < n; k++) {
                dp2[2][i][k] = min(dp2[2][i][k], dp2[1][i][j] + dp[2][j][k]);
            }
        }
    }

    ll ans = INF;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            ans=min(ans,dp2[2][i][j]+dp[3][j][i]);
        }
    }
    cout << sum - ans;
}
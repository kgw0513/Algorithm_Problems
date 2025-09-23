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
#pragma warning(disable:4996)
#define fi first
#define se second
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

//dp[현 위치][2^n의 이동횟수]={이동했을때의 위치, 비용}
ll_ll dp[40002][16];
vector<ll_ll>lines[40002];
ll depth[40002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, c;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        lines[a].push_back({ b,c });
        lines[b].push_back({ a,c });
    }

    lines[0].push_back({ 1,0 });
    lines[1].push_back({ 0,0 });

    queue<ll_ll>arr;
    arr.push({ 1,0 });
    while (!arr.empty()) {
        int last_p = arr.front().se;
        int now_p = arr.front().fi;
        arr.pop();
        depth[now_p] = depth[last_p] + 1;
        for (int i = 0; i < lines[now_p].size(); i++) {
            int next_p = lines[now_p][i].fi;
            int go_dist = lines[now_p][i].se;
            if (next_p == last_p)continue;
            dp[next_p][0] = { now_p,go_dist };
            for (int j = 1; j < 16; j++) {
                dp[next_p][j].fi = dp[dp[next_p][j - 1].fi][j - 1].fi;
                dp[next_p][j].se = dp[dp[next_p][j - 1].fi][j - 1].se + dp[next_p][j - 1].se;
            }
            arr.push({ next_p,now_p });
        }
    }

    //위 과정들은 최소공통조상 세팅 코드.

    //이제 두 노드쌍이 주어지면 가까운 조상 찾아 거리합으로 출력.
    cin >> m;
    while (m--) {
        cin >> a >> b;
        ll ans = 0;

        ll a_depth = depth[a];
        ll b_depth = depth[b];
        if (a_depth > b_depth) {
            ll diff = a_depth - b_depth;
            for (int i = 15; i >= 0; i--) {
                if (((1ll << i) & diff) != 0) {
                    ans += dp[a][i].se;
                    a = dp[a][i].fi;
                }
            }
        }
        else if(a_depth<b_depth){
            ll diff = b_depth - a_depth;
            for (int i = 15; i >= 0; i--) {
                if (((1ll << i) & diff) != 0) {
                    ans += dp[b][i].se;
                    b = dp[b][i].fi;
                }
            }
        }

        if (a == b) {
            cout << ans << "\n";
            continue;
        }

        for (int i = 15; i >= 0; i--) {
            if (dp[a][i].fi != dp[b][i].fi) {
                ans += dp[a][i].se + dp[b][i].se;
                a = dp[a][i].fi;
                b = dp[b][i].fi;
            }
        }

        ans += dp[a][0].se + dp[b][0].se;
        cout << ans << "\n";
    }
}
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

int depth[100002];

intint min_dp[100002][18];
intint max_dp[100002][18];

vector<intint>lines[100002];

void dfs(const int p, const int lp,const int d) {
    depth[p] = d;
    for (intint h : lines[p])
    {
        int np = h.fi;
        int dist = h.se;
        if (np == lp)continue;
        dfs(np, p, d + 1);
        min_dp[np][0] = { p,dist };
        max_dp[np][0] = { p,dist };
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> w;
        lines[a].push_back({ b,w });
        lines[b].push_back({ a,w });
    }

    dfs(1, -1, 1);
    for (int len = 1; len < 18; len++) {
        for (int i = 1; i <= n; i++) {
            min_dp[i][len].fi = min_dp[min_dp[i][len - 1].fi][len - 1].fi;
            min_dp[i][len].se = min(min_dp[i][len - 1].se, min_dp[min_dp[i][len - 1].fi][len - 1].se);

            max_dp[i][len].fi = max_dp[max_dp[i][len - 1].fi][len - 1].fi;
            max_dp[i][len].se = max(max_dp[i][len - 1].se, max_dp[max_dp[i][len - 1].fi][len - 1].se);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        //{최솟값,최댓값}
        intint ans = { nINF,0 };
        
        if (depth[a] > depth[b]) {
            int gap = depth[a] - depth[b];
            for (int len = 17; len >= 0; len--) {
                if ((gap & (1 << len)) == 0)continue;
                ans.fi = min(ans.fi, min_dp[a][len].se);
                ans.se = max(ans.se, max_dp[a][len].se);
                a = min_dp[a][len].fi; // max_dp[a][len].fi랑 같으니 걱정 ㄴㄴ
            }
        }
        else if (depth[a] < depth[b]) {
            int gap = depth[b] - depth[a];
            for (int len = 17; len >= 0; len--) {
                if ((gap & (1 << len)) == 0)continue;
                ans.fi = min(ans.fi, min_dp[b][len].se);
                ans.se = max(ans.se, max_dp[b][len].se);
                b = min_dp[b][len].fi; // max_dp[a][len].fi랑 같으니 걱정 ㄴㄴ
            }
        }

        if (a != b) { //높이는 같으나 같은 위치 도달하지 않았을때
            for (int len = 17; len >= 0; len--) {
                if (min_dp[a][len].fi == min_dp[b][len].fi)continue;
                ans.fi = min(ans.fi, min_dp[a][len].se);
                ans.se = max(ans.se, max_dp[a][len].se);
                a = min_dp[a][len].fi; // max_dp[a][len].fi랑 같으니 걱정 ㄴㄴ

                ans.fi = min(ans.fi, min_dp[b][len].se);
                ans.se = max(ans.se, max_dp[b][len].se);
                b = min_dp[b][len].fi; // max_dp[a][len].fi랑 같으니 걱정 ㄴㄴ
            }

            ans.fi = min(ans.fi, min_dp[a][0].se);
            ans.se = max(ans.se, max_dp[a][0].se);
            a = min_dp[a][0].fi; // max_dp[a][len].fi랑 같으니 걱정 ㄴㄴ

            ans.fi = min(ans.fi, min_dp[b][0].se);
            ans.se = max(ans.se, max_dp[b][0].se);
            b = min_dp[b][0].fi; // max_dp[a][len].fi랑 같으니 걱정 ㄴㄴ
        }

        cout << ans.fi << " " << ans.se << "\n";
    }
}
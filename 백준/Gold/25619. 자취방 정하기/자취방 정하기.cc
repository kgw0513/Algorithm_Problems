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

vector<ll_ll>lines[200002];
__int128 cost[200002];

struct cmp {
    bool operator()(ll_ll& a, ll_ll& b) {
        return a.fi > b.fi;
    }
};
//{비용,정점}
priority_queue<ll_ll, vector<ll_ll>,cmp>arr;

void bfs(ll p) {
    queue<ll>arr;
    arr.push(p);
    vector<ll>ans;
    cost[p] = -lINF;
    while (arr.size()) {
        ll now_p = arr.front();
        arr.pop();
        ans.push_back(now_p);
        for (ll_ll& h : lines[now_p]) {
            if (cost[h.fi] == -lINF)continue;
            cost[h.fi] = -lINF;
            arr.push(h.fi);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ll(ans.size()) - 1 << "\n";
    if (!ans.empty()) {
        cout << ans[1];
        for (int i = 2; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(cost, cost + 200002, lINF);
    cost[1] = 0;

    ll n, m, t, a, b, c, d;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c >> d;
        lines[a].push_back({ b,(c + d) });
        lines[b].push_back({ a,(c + d) });
    }
    cin >> t;

    arr.push({ 0,1 });
    while (arr.size()) {
        ll now_cost = arr.top().fi;
        ll now_p = arr.top().se;
        arr.pop();
        if (cost[now_p] != now_cost)continue;

        for (ll_ll& h : lines[now_p]) {
            if (h.se < 0) {
                bfs(1);
                return 0;
            }
            if ((h.se + now_cost) < cost[h.fi]) {
                arr.push({ now_cost + h.se,h.fi });
                cost[h.fi] = now_cost + h.se;
            }
        }
    }

    vector<int>ans;
    for (int i = 2; i <= n; i++) {
        if (cost[i] != lINF && cost[i] <= t * 2) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    if (!ans.empty()) {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
    }
}
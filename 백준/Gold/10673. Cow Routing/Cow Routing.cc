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

vector<ll_ll2>lines[1002];

struct cmp {
    bool operator()(ll_ll2& a, ll_ll2& b) {
        return a.se > b.se;
    }
};
priority_queue<ll_ll2, vector<ll_ll2>, cmp>arr;
ll_ll visit[1002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 1002; i++) {
        visit[i] = { lINF,lINF };
    }
    ll s, e, a, n, t;
    cin >> s >> e >> t;
    while (t--) {
        cin >> a >> n;
        vector<ll>brr(n);
        for (ll& h : brr) {
            cin >> h;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll h1 = brr[i];
                ll h2 = brr[j];
                lines[h1].push_back({ h2,{a,j - i} });
            }
        }
    }

    visit[s] = { 0,0 };
    arr.push({ s,{0,0} });
    while (arr.size()) {
        ll now_h = arr.top().fi;
        ll now_cost = arr.top().se.fi;
        ll now_flight = arr.top().se.se;
        arr.pop();
        if (visit[now_h].fi != now_cost || visit[now_h].se != now_flight)continue;
        for (ll_ll2& h : lines[now_h]) {
            ll new_h = h.fi;
            ll new_cost = now_cost + h.se.fi;
            ll new_flight = now_flight + h.se.se;
            if (new_cost > visit[new_h].fi)continue;
            if (new_cost == visit[new_h].fi && new_flight >= visit[new_h].se)continue;
            visit[new_h] = { new_cost,new_flight };
            arr.push({ new_h,{new_cost,new_flight} });
        }
    }
    if (visit[e].se == lINF)cout << "-1 -1";
    else cout << visit[e].fi << " " << visit[e].se;
}
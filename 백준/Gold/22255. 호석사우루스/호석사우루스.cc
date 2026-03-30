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

ll maps[102][102];
ll visit[3][102][102];

const vector<ll_ll>dxdy[3] = {
    {{-1,0},{1,0},{0,-1},{0,1}},
    {{-1,0},{1,0}},
    {{0,-1},{0,1}}
};

struct cmp {
    bool operator()(ll2_ll2& a, ll2_ll2& b) {
        return a.fi.fi > b.fi.fi;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int j = 0; j < 102; j++) {
        for (int k = 0; k < 102; k++) {
            for (int i = 0; i < 3; i++) {
                visit[i][j][k] = nlINF;
            }
            maps[j][k] = -1;
        }
    }
    ll n, m;
    ll_ll s, e;
    cin >> n >> m >> s.fi >> s.se >> e.fi >> e.se;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maps[i][j];
        }
    }

    priority_queue<ll2_ll2, vector<ll2_ll2>, cmp>arr;
    arr.push({ {0,1},s });
    visit[0][s.fi][s.se] = 0;

    ll now_move = 0;
    while (!arr.empty()) {
        ll now_cost = arr.top().fi.fi;
        ll now_move = arr.top().fi.se;
        ll_ll now_p = arr.top().se;
        arr.pop();
        if (visit[(now_move + 2) % 3][now_p.fi][now_p.se] != now_cost)continue;

        for (const ll_ll& xy : dxdy[now_move % 3]) {
            ll_ll new_p = { now_p.fi + xy.fi,now_p.se + xy.se };
            if (maps[new_p.fi][new_p.se] == -1)continue;
            ll new_cost = now_cost + maps[new_p.fi][new_p.se];
            if (visit[now_move % 3][new_p.fi][new_p.se] <= new_cost)continue;
            visit[now_move % 3][new_p.fi][new_p.se] = new_cost;
            //cout << now_move << "에서, " << new_p.fi << "," << new_p.se << "에 " << new_cost << "비용 듦.\n";
            arr.push({ {new_cost,now_move + 1},new_p });
        }
    }

    ll ans = -1;
    for (int i = 0; i < 3; i++) {
        if (visit[i][e.fi][e.se] < nlINF) {
            if (ans == -1)ans = visit[i][e.fi][e.se];
            else ans = min(ans, visit[i][e.fi][e.se]);
        }
    }
    cout << ans;
}
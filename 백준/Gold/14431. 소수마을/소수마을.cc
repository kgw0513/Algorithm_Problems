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

bool not_sosu[9000] = { 1,1 };
ll dist[4010][4010];

ll visit[4010];

struct cmp {
    bool operator()(ll_ll& a, ll_ll& b) {
        return a.se > b.se;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(visit, visit + 9000, nlINF);

    for (int i = 2; i < 9000; i++) {
        if (not_sosu[i])continue;
        for (int j = i * i; j < 9000; j += i) {
            not_sosu[j] = true;
        }
    }
    ll_ll s, e, w;
    ll n;
    cin >> s.fi >> s.se >> e.fi >> e.se >> n;
    vector<ll_ll>inputs = { s };
    while (n-->0) {
        cin >> w.fi >> w.se;
        inputs.push_back(w);
    }
    inputs.push_back(e);

    for (int i = 0; i < inputs.size(); i++) {
        for (int j = i+1; j < inputs.size(); j++) {
            dist[i][j] = sqrt((inputs[i].fi - inputs[j].fi) * (inputs[i].fi - inputs[j].fi) + (inputs[i].se - inputs[j].se) * (inputs[i].se - inputs[j].se));
            dist[j][i] = dist[i][j];
        }
    }

    visit[0] = 0;
    priority_queue<ll_ll, vector<ll_ll>, cmp>arr;
    arr.push({ 0,0 });

    while (!arr.empty()) {
        ll now_p = arr.top().fi;
        ll now_cost = arr.top().se;
        arr.pop();
        
        if (visit[now_p] != now_cost)continue;

        for (ll next_p = 0; next_p < inputs.size(); next_p++) {
            if (now_p == next_p)continue;
            if (not_sosu[dist[now_p][next_p]])continue;
            ll new_cost = now_cost + dist[now_p][next_p];
            if (visit[next_p] <= new_cost)continue;
            visit[next_p] = new_cost;
            arr.push({ next_p,new_cost });
        }
    }

    if (visit[inputs.size() - 1] == nlINF) {
        cout << -1;
        return 0;
    }

    cout << visit[inputs.size() - 1];
}
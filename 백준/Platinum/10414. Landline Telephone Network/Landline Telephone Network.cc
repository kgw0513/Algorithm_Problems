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

struct cmp {
    bool operator()(int_int2& a, int_int2& b) {
        return a.fi > b.fi;
    }
};

int costs[1002][1002];

vector<intint>lines[1002];

int Union[1002];

int Find(int n) {
    if (Union[n] == n)return n;
    return Union[n] = Find(Union[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 1002; i++) {
        Union[i] = i;
    }

    int n, m, p, a, b, w;
    cin >> n >> m >> p;
    set<int>insec;
    for (int i = 0; i < p; i++) {
        cin >> w;
        insec.insert(w);
    }

    priority_queue<int_int2, vector<int_int2>, cmp>arr; //안전한 간선

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        lines[a].push_back({ b,w });
        lines[b].push_back({ a,w });
        costs[a][b] = w;
        costs[b][a] = w;
        if (!(insec.find(a) != insec.end() || insec.find(b) != insec.end())) {
            arr.push({ w,{a,b} });
        }
    }

    int ans = 0;

    while (!arr.empty()) {
        w = arr.top().fi;
        a = arr.top().se.fi;
        b = arr.top().se.se;

        arr.pop();

        a = Find(a);
        b = Find(b);

        if (a == b)continue;
        ans += w;
        if (a > b)swap(a, b);
        Union[a] = b;
    }

    if (p == n) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (costs[i][j] == 0) {
                    cout << "impossible";
                    return 0;
                }
                ans += costs[i][j];
            }
        }

        cout << ans;
        return 0;
    }

    for (int ip : insec) {
        int find_p = -1;
        int min_cost = INF;
        for (const intint& h : lines[ip]) {
            int cp = h.fi;
            if (insec.find(cp) != insec.end())continue;
            int cost = h.se;
            if (min_cost > cost) {
                min_cost = cost;
                find_p = cp;
            }
        }

        if (find_p == -1) {
            continue;
        }

        ans += min_cost;

        find_p = Find(find_p);
        ip = Find(ip);

        if (find_p > ip)swap(find_p, ip);
        Union[find_p] = ip;
    }

    int check_union = Find(1);
    for (int i = 1; i <= n; i++) {
        if (check_union != Find(i)) {
            cout << "impossible";
            return 0;
        }
    }

    cout << ans;
}
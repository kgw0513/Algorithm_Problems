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

class Tree {
    int Nodes;
    unordered_map<int, vector<ll_ll>>Lines;
    unordered_map<intint, ll_ll, pair_hash>dp;

public:
    Tree() = delete;
    Tree(int n) :Nodes(n) {
        int a, b, c;
        for (int i = 1; i < n; i++) {
            cin >> a >> b >> c;
            Lines[a].push_back({ b,c });
            Lines[b].push_back({ a,c });
        }
    }

    ~Tree() = default;

    ll_ll Tree_Min_Dist() {
        ll_ll ans = { -1,lINF };
        for (int i = 1; i <= Nodes; i++) {
            if (Nodes >= 3 && Lines[i].size() == 1)continue;
            ll_ll h = Cal_all_dist(i, -1);
            if (ans.se > h.fi) {
                ans = { i,h.fi };
            }
        }

        return ans;
    }
private:
    ll_ll Cal_all_dist(int p,int lp) {
        if (dp.find({ p,lp }) != dp.end())return dp[{p, lp}];

        ll collect_Nodes = 1; //본인포함
        ll sum_dist = 0;

        for (intint nps : Lines[p]) {
            int np = nps.fi;
            if (np == lp)continue;
            ll dist = nps.se;
            ll_ll h = Cal_all_dist(np, p);
            sum_dist += h.fi + (h.se * dist);
            collect_Nodes += h.se;
        }

        return dp[{p, lp}] = { sum_dist, collect_Nodes };
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n;
    Tree a(n);
    cin >> m;
    Tree b(m);

    ll_ll a_dist = a.Tree_Min_Dist();
    ll_ll b_dist = b.Tree_Min_Dist();

    cout << a_dist.fi << " " << b_dist.fi << "\n";
    cout << a_dist.se * m + b_dist.se * n + n * m;
}
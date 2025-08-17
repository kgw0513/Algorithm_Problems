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

inline ll ccw(ll_ll a, ll_ll b, ll_ll c) {
    return (a.fi * b.se + b.fi * c.se + c.fi * a.se) - (a.se * b.fi + b.se * c.fi + c.se * a.fi);
}

bool a_cross_b(ll2_ll2 a, ll2_ll2 b) {
    ll h_a1 = ccw(a.fi, a.se, b.fi);
    ll h_a2 = ccw(a.fi, a.se, b.se);
    ll h_b1 = ccw(b.fi, b.se, a.fi);
    ll h_b2 = ccw(b.fi, b.se, a.se);
    if (h_a1 == 0 && h_a2 == 0) {
        if (a.fi.fi <= b.fi.fi && b.fi.fi <= a.se.fi
            && a.fi.se <= b.fi.se && b.fi.se <= a.se.se)return true;
        if (a.fi.fi <= b.se.fi && b.se.fi <= a.se.fi
            && a.fi.se <= b.se.se && b.se.se <= a.se.se)return true;
        if (b.fi.fi <= a.fi.fi && a.fi.fi <= b.se.fi
            && b.fi.se <= a.fi.se && a.fi.se <= b.se.se)return true;
        if (b.fi.fi <= a.se.fi && a.se.fi <= b.se.fi
            && b.fi.se <= a.se.se && a.se.se <= b.se.se)return true;


        if (a.se.fi <= b.fi.fi && b.fi.fi <= a.fi.fi
            && a.fi.se <= b.fi.se && b.fi.se <= a.se.se)return true;
        if (a.se.fi <= b.se.fi && b.se.fi <= a.fi.fi
            && a.fi.se <= b.se.se && b.se.se <= a.se.se)return true;
        if (b.se.fi <= a.fi.fi && a.fi.fi <= b.fi.fi
            && b.fi.se <= a.fi.se && a.fi.se <= b.se.se)return true;
        if (b.se.fi <= a.se.fi && a.se.fi <= b.fi.fi
            && b.fi.se <= a.se.se && a.se.se <= b.se.se)return true;

        return false;
    }
    if (h_a1 * h_a2 <= 0 && h_b1 * h_b2 <= 0)return true;
    return false;
}

inline bool check_cross(ll2_ll2 a, ll2_ll2 b) {
    if (!a_cross_b(a, b) || !a_cross_b(b, a))return false;
    return true;
}

int2_int2 inputs[3001];
int Union[3001];
int Counting[3001];
int find(int n) {
    if (Union[n] == n)return n;
    return Union[n] = find(Union[n]);
}

bool visit[3001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 3000; i++) {
        Union[i] = i;
        Counting[i] = 1;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inputs[i].fi.fi;
        cin >> inputs[i].fi.se;
        cin >> inputs[i].se.fi;
        cin >> inputs[i].se.se;
        for (int j = 1; j < i; j++) {
            if (!check_cross(inputs[i], inputs[j]))continue;
            int a = find(Union[i]);
            int b = find(Union[j]);
            if (a == b)continue;
            if (a > b)swap(a, b);
            Counting[a] += Counting[b];
            Union[b] = a;
        }
    }
    
    int ans_count = 0;
    int max_ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[find(Union[i])])continue;
        visit[find(Union[i])] = true;
        ans_count++;
        max_ans = max(max_ans, Counting[find(Union[i])]);
    }

    cout << ans_count << "\n" << max_ans;
}
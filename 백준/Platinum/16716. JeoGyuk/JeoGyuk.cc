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

int n;
intint enemy_pos[20];
intint a, b;

pair<bool, intint>visit[2][1 << 20];
unordered_map<intint, int, pair_hash>arr;
int arr_ver_col[2][2];
unordered_map<intint, int, pair_hash>brr;
int brr_ver_col[2][2];

intint pos_state[2][20];

intint cal(int kill_state, int p) {
    if (kill_state == (1 << n) - 1)return { 0,0 };
    if (visit[p][kill_state].fi)return visit[p][kill_state].se;

    //cout << kill_state << "," << p << "들.\n";
    visit[p][kill_state].fi = true;
    visit[p][kill_state].se = { nINF,nINF };

    for (int i = 0; i < n; i++) {
        if ((kill_state & (1 << i)) != 0)continue;

        int h1 = pos_state[p][i].fi;
        int h2 = pos_state[p][i].se;

        bool h1_match = enemy_pos[i].fi == a.fi;
        if (p == 1)h1_match = enemy_pos[i].fi == b.fi;

        bool h2_match = enemy_pos[i].se == a.se;
        if (p == 1)h2_match = enemy_pos[i].se == b.se;

        int new_kill_state = kill_state;
        if (!h1_match && !h2_match) {
            if (p == 0)new_kill_state |= arr[{h1, h2}];
            else new_kill_state |= brr[{h1, h2}];
        }
        else if (h1_match) {
            if (p == 0) {
                new_kill_state |= arr_ver_col[h1][h2];
            }
            else new_kill_state |= brr_ver_col[h1][h2];
        }
        else {
            if (p == 0)new_kill_state |= arr_ver_col[h1][h2];
            else new_kill_state |= brr_ver_col[h1][h2];
        }

        {
            intint h = cal(new_kill_state, p);
            h.fi++;
            if (visit[p][kill_state].se.fi > h.fi || \
                (visit[p][kill_state].se.fi == h.fi && visit[p][kill_state].se.se > h.se))\
                visit[p][kill_state].se = h;
        }
        if (p == 0) {
            intint h = cal(new_kill_state, 1);
            h.fi++;
            h.se++;
            if (visit[p][kill_state].se.fi > h.fi || \
                (visit[p][kill_state].se.fi == h.fi && visit[p][kill_state].se.se > h.se))\
                visit[p][kill_state].se = h;
        }
    }

    if (p == 0) {
        intint h = cal(kill_state, 1);
        h.se++;
        if (visit[p][kill_state].se.fi > h.fi || \
            (visit[p][kill_state].se.fi == h.fi && visit[p][kill_state].se.se > h.se))\
            visit[p][kill_state].se = h;
    }
    //cout << kill_state << "," << p << " : " << visit[p][kill_state].se.fi<<","<<visit[p][kill_state].se.se << "?\n";
    return visit[p][kill_state].se;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        intint& w = enemy_pos[i];
        cin >> w.fi >> w.se;
    }
    cin >> a.fi >> a.se >> b.fi >> b.se;

    for (int i = 0; i < n; i++) {
        int h1 = enemy_pos[i].fi - a.fi;
        int h2 = enemy_pos[i].se - a.se;
        if (h1 == 0) {
            arr_ver_col[0][enemy_pos[i].se < a.se] += (1 << i);
            pos_state[0][i] = { 0,enemy_pos[i].se < a.se };
            continue;
        }
        if (h2 == 0) {
            //cout << 1 << "," << int(enemy_pos[i].se < a.se) << "에 들.\n";
            arr_ver_col[1][enemy_pos[i].fi < a.fi] += (1 << i);
            pos_state[0][i] = { 1,enemy_pos[i].fi < a.fi };
            continue;
        }
        int h3 = abs(h1), h4 = abs(h2);
        while (h3 % h4 != 0) {
            int h5 = h3 % h4;
            h3 = h4;
            h4 = h5;
        }
        h1 /= h4;
        h2 /= h4;

        //cout << i << "의 ";
        //cout << h1 << "," << h2 << " 첫번째 위치.\n";

        arr[{h1, h2}] += (1 << i);
        pos_state[0][i] = { h1,h2 };
    }

    for (int i = 0; i < n; i++) {
        int h1 = enemy_pos[i].fi - b.fi;
        int h2 = enemy_pos[i].se - b.se;
        if (h1 == 0) {
            brr_ver_col[0][enemy_pos[i].se < b.se] += (1 << i);
            pos_state[1][i] = { 0,enemy_pos[i].se < b.se };
            continue;
        }
        if (h2 == 0) {
            //cout << 1 << "," << int(enemy_pos[i].se < a.se) << "에 들.\n";
            brr_ver_col[1][enemy_pos[i].fi < b.fi] += (1 << i);
            pos_state[1][i] = { 1,enemy_pos[i].fi < b.fi };
            continue;
        }
        int h3 = abs(h1), h4 = abs(h2);
        while (h3 % h4 != 0) {
            int h5 = h3 % h4;
            h3 = h4;
            h4 = h5;
        }
        h1 /= h4;
        h2 /= h4;

        //cout << i << "의 ";
        //cout << h1 << "," << h2 << " 두번째 위치.\n";

        brr[{h1, h2}] += (1 << i);
        pos_state[1][i] = { h1,h2 };
    }

    intint ans = cal(0, 0);

    cout << ans.fi << " " << ans.se;
}
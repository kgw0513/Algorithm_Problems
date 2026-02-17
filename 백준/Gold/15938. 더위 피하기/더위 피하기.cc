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

bool block[502][502];
ll dp[202][502][502];

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 502; i++) {
        for (int j = 0; j < 502; j++) {
            block[i][j] = true;
        }
    }

    for (int i = 1; i < 501; i++) {
        for (int j = 1; j < 501; j++) {
            block[i][j] = false;
        }
    }

    intint s, e;
    int t, n;

    cin >> s.fi >> s.se >> t >> e.fi >> e.se >> n;
    if (abs(s.fi - e.fi) + abs(s.se - e.se) > t) {
        //너무 멀어서 도저히 쓰러지기전 갈 수 없다
        cout << 0;
        return 0;
    }

    vector<intint>arr(n);
    for (intint& w : arr) {
        cin >> w.fi >> w.se;
    }

    intint dpxy_plus = { 250,250 };
    //성원이의 현 위치를 0,0으로 두고 t가 최대 200이라 좌표 -250~250정도 넉넉하게 잡아둔 뒤 돌리면 된다.
    e = { e.fi - s.fi,e.se - s.se };
    for (intint& w : arr) {
        w = { w.fi - s.fi,w.se - s.se };

        //cout << w.fi << "," << w.se << "위치 막기.\n";

        if (0 <= w.fi + dpxy_plus.fi && w.fi + dpxy_plus.fi <= 500
            && 0 <= w.se + dpxy_plus.se && w.se + dpxy_plus.se <= 500) {
            block[w.fi + dpxy_plus.fi][w.se + dpxy_plus.se] = true;
        }
    }

    s = { 0,0 };
    //cout << s.fi + dpxy_plus.fi << ","<<s.se + dpxy_plus.se << "?\n";
    dp[0][s.fi + dpxy_plus.fi][s.se + dpxy_plus.se] = 1;

    for (int tc = 1; tc <= t; tc++) {
        for (int i = 1; i < 501; i++) {
            for (int j = 1; j < 501; j++) {
                if (block[i][j])continue;
                if (i == e.fi + dpxy_plus.fi && j == e.se + dpxy_plus.se) {
                    dp[tc][i][j] += dp[tc - 1][i][j];
                    dp[tc][i][j]%=MOD1;
                    continue;
                }
                for (intint xy : dxdy) {
                    intint p = { i + xy.fi,j + xy.se };
                    if (block[p.fi][p.se])continue;
                    dp[tc][p.fi][p.se] += dp[tc - 1][i][j];
                    dp[tc][p.fi][p.se] %= MOD1;
                }
            }
        }

        //cout << tc << ":\n";
        //for (int i = -5; i <= 5; i++) {
        //    for (int j = -5; j <= 5; j++) {
        //        cout << dp[tc][i + dpxy_plus.fi][j + dpxy_plus.se] << " ";
        //    }
        //    cout << "\n";
        //}
    }

    //cout << e.fi << "," << e.se << "위치.\n";
    cout << dp[t][e.fi + dpxy_plus.fi][e.se + dpxy_plus.se];
}
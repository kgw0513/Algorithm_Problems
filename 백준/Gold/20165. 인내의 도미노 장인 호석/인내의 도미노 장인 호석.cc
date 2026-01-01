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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

int n, m, k;
int arr[102][102];
intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
int turn_dxdy_p[26];

int cal(intint p, int dxdy_p) {
    if (arr[p.fi][p.se] <= 0)return 0;
    int sum = 0;
    int move_count = 1;
    while (1 <= p.fi && p.fi <= n && 1 <= p.se && p.se <= m && move_count >= 1) {
        if (arr[p.fi][p.se] > 0) {
            sum++;
            move_count = max(move_count, arr[p.fi][p.se]);
            arr[p.fi][p.se] *= -1;
        }
        p.fi += dxdy[dxdy_p].fi;
        p.se += dxdy[dxdy_p].se;
        move_count--;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    turn_dxdy_p['E' - 'A'] = 3;
    turn_dxdy_p['W' - 'A'] = 2;
    turn_dxdy_p['N' - 'A'] = 0;
    turn_dxdy_p['S' - 'A'] = 1;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    while (k--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int p = turn_dxdy_p[c - 'A'];
        ans += cal({ a,b }, p);
        cin >> a >> b;
        if (arr[a][b] <= 0) {
            arr[a][b] *= -1;
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (arr[i][j] > 0 ? 'S' : 'F') << (j != m ? " " : "");
        }
        cout << "\n";
    }
}
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

int ans[4002];
int state[2002][2002];

//상우하좌
intint dxdy[4] = { {-1,0},{0,1},{1,0},{0,-1} };

inline int find_num(intint p, int n, int m) {
    if (p.se == 0)return p.fi;
    if (p.fi == 0)return (2 * n + 2 * m + 1 - p.se);
    if (p.se == m + 1)return (2 * n + m + 1 - p.fi);
    if (p.fi == n + 1)return n + p.se;
    exit(-1);
}

void moving(intint& p, int& arrow, int h) {
    if (h == 1) {
        if (arrow % 2 == 0) {
            arrow++;
            arrow %= 4;
        }
        else {
            arrow += 3;
            arrow %= 4;
        }
    }

    p = { p.fi + dxdy[arrow].fi,p.se + dxdy[arrow].se };

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> state[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        int j = 0;
        int arrow = 1;
        int num1 = find_num({ i,j }, n, m);
        if (ans[num1] != 0)continue;

        intint p = { i,j };
        while (1) {
            moving(p, arrow, state[p.fi][p.se]);
            if (!(1 <= p.fi && p.fi <= n && 1 <= p.se && p.se <= m))break;
        }
        int num2 = find_num(p, n, m);

        ans[num1] = num2;
        ans[num2] = num1;
    }

    for (int j = 1; j <= m; j++) {
        int i = n + 1;
        int arrow = 0;
        int num1 = find_num({ i,j }, n, m);
        if (ans[num1] != 0)continue;

        intint p = { i,j };
        while (1) {
            moving(p, arrow, state[p.fi][p.se]);
            if (!(1 <= p.fi && p.fi <= n && 1 <= p.se && p.se <= m))break;
        }
        int num2 = find_num(p, n, m);

        ans[num1] = num2;
        ans[num2] = num1;
    }

    for (int i = n; i >= 1; i--) {
        int j = m + 1;
        int arrow = 3;
        int num1 = find_num({ i,j }, n, m);
        if (ans[num1] != 0)continue;

        intint p = { i,j };
        while (1) {
            moving(p, arrow, state[p.fi][p.se]);
            if (!(1 <= p.fi && p.fi <= n && 1 <= p.se && p.se <= m))break;
        }
        int num2 = find_num(p, n, m);

        ans[num1] = num2;
        ans[num2] = num1;
    }

    for (int j = m; j >= 1; j--) {
        int i = 0;
        int arrow = 2;
        int num1 = find_num({ i,j }, n, m);
        if (ans[num1] != 0)continue;

        intint p = { i,j };
        while (1) {
            moving(p, arrow, state[p.fi][p.se]);
            if (!(1 <= p.fi && p.fi <= n && 1 <= p.se && p.se <= m))break;
        }
        int num2 = find_num(p, n, m);

        ans[num1] = num2;
        ans[num2] = num1;
    }

    cout << ans[1];
    for (int i = 2; i <= 2 * n + 2 * m; i++) {
        cout << " " << ans[i];
    }
}
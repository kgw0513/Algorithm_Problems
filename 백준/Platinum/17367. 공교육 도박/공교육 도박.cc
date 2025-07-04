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
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
constexpr unsigned long long MOD3 = 998244353;
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

double dp[998][7][7][7];

inline double cal(int a, int b, int c) {
    double ans = 0;
    if (a == b && b == c) {
        ans += 10000 + a * 1000;
    }
    else if (a == b || b == c) {
        ans += 1000 + b * 100;
    }
    else if (a == c) {
        ans += 1000 + a * 100;
    }
    else {
        ans += 100 * max({ a,b,c });
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int a = 1; a <= 6; a++) {
        for (int b = 1; b <= 6; b++) {
            for (int c = 1; c <= 6; c++) {
                dp[0][a][b][c] = cal(a, b, c);
            }
        }
    }
    for (int n = 1; n <= 997; n++) {
        for (int b = 1; b <= 6; b++) {
            for (int c = 1; c <= 6; c++) {
                for (int d = 1; d <= 6; d++) {
                    for (int a = 1; a <= 6; a++) {
                        dp[n][b][c][d] += dp[n - 1][a][b][c];
                    }
                    dp[n][b][c][d] /= 6;
                    dp[n][b][c][d] = max(dp[n][b][c][d], cal(b, c, d));
                }
            }
        }
    }

    int n;
    cin >> n;
    n -= 3;
    double ans = 0;
    for (int a = 1; a <= 6; a++) {
        for (int b = 1; b <= 6; b++) {
            for (int c = 1; c <= 6; c++) {
                ans += dp[n][a][b][c];
            }
        }
    }
    ans /= 216;
    cout.precision(12);
    cout << ans;
}
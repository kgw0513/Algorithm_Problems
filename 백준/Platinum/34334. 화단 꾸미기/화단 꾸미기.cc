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

ll inputs[102];
ll dp[1 << 10][102];
ll multi[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> inputs[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> multi[j];
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] += dp[0][i - 1] + inputs[i];
    }

    for (int state = 0; state < (1 << m); state++) {
        for (int deco = 0; deco <= m; deco++) {
            if (((1 << deco) & state) == 0)continue;
            int last_state = (state - (1 << deco));
            //cout << deco << "," << state << "시작.\n";

            for (int length = 0; length <= k; length++) {
                ll sum = 0;
                for (int i = 1; i <= n; i++) {
                    sum += inputs[i] * multi[deco];
                    if (i >= length) {
                        sum -= inputs[i - length] * multi[deco];
                        dp[state][i] = max(dp[state][i], dp[last_state][i - length] + sum);
                        //cout << length << "/" << i << " | dp[" << state << "][" << i << "] : " << dp[state][i] << "\n";
                    }
                    dp[state][i] = max(dp[state][i], dp[state][i - 1] + inputs[i]);
                }
            }
        }
    }

    cout << dp[(1 << m) -1][n];
}
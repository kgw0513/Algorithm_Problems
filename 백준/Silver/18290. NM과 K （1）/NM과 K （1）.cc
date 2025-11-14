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
#include <cassert>
#pragma warning(disable:4996)
#define fi first
#define se second
#define print_end "\n"
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

int dp[12][1 << 10][62];
int state[12][12];

int bit_count(int n) {
    int ans = 0;
    while (n > 0) {
        n -= (n & -n);
        ans++;
    }
    return ans;
}

int bit_num_sum(int n,int m,int height) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if ((n & (1 << i)) != 0) {
            sum += state[height][i+1];
            //cout << n << "," << height << "에서 " << i << "에 " << state[height][i+1] << "더함.\n";
        }
    }
    //cout << sum << "반환.\n";
    return sum;
}

bool is_bit_neighbor(int n,int m) {
    for (int i = 1; i < m; i++) {
        if (((n & (1 << (i - 1))) != 0) && ((n & (1 << i)) != 0))return true;
    }
    return false;
}

bool is_two_num_neighbor(int a, int b) {
    return (a & b) != 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 1024; j++) {
            for (int k = 0; k < 62; k++) {
                dp[i][j][k] = -nINF;
            }
        }
    }
    dp[0][0][0] = 0;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> state[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int last_j = 0; last_j < (1 << m); last_j++) {
            if (is_bit_neighbor(last_j,m))continue;
            for (int now_j = 0; now_j < (1 << m); now_j++) {
                if (is_bit_neighbor(now_j,m))continue;
                if (is_two_num_neighbor(last_j, now_j))continue;
                for (int counting = 0; counting <= 50; counting++) {
                    dp[i][now_j][counting + bit_count(now_j)] = max(dp[i][now_j][counting + bit_count(now_j)], dp[i - 1][last_j][counting]+ bit_num_sum(now_j,m,i));
                }
            }
        }
    }

    int ans = -nINF;
    for (int now_j = 0; now_j < (1 << m); now_j++) {
        ans = max(ans, dp[n][now_j][k]);
    }

    cout << ans;
}
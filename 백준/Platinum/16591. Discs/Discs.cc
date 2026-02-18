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

//[마지막 방문 위치][상태]
bool visit[16][1 << 16];
double dp[16][1 << 16];

int n;
vector<dd>points;

inline double point_dist(dd a, dd b) {
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

// state 안한것들 남은거 1:안씀, 0:씀
double dfs(int state, int now_p,const int left_count) {
    if (visit[now_p][state])return dp[now_p][state];
    visit[now_p][state] = true;
    if (state == 0)return dp[now_p][state] = 0;

    bool insert_first = false;
    for (int next_p = 0; next_p < n; next_p++) {
        if ((state & (1 << next_p)) == 0)continue; //이미 쓴 판은 스킵
        double min_radius_sum = dfs(state - (1 << next_p), next_p,left_count-1) + point_dist(points[now_p], points[next_p])* left_count;
        if (!insert_first || dp[now_p][state] > min_radius_sum) {
            insert_first = true;
            dp[now_p][state] = min_radius_sum;
        }
    }

    //cout << "dp1 = ";
    //cout << now_p << "|" << state << ":" << dp[now_p][state] << "\n";
    return dp[now_p][state];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    points.resize(n);
    for (dd& w : points) {
        cin >> w.fi >> w.se;
    }

    double ans = dfs((1 << n) - 1 - (1 << 0), 0, n - 1);

    for (int i = 1; i < n; i++) {
        if (ans > dfs((1 << n) - 1 - (1 << i), i, n - 1)) {
            ans = dfs((1 << n) - 1 - (1 << i), i, n - 1);
        }
    }

    cout.precision(12);
    cout << ans;
}
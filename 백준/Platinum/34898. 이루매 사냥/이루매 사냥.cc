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

bool visit[102][10002];
//받은 일차수 , 비용에 대한 냅색 = 냅색 최대값
ll dp[102][10002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, c;
    cin >> n >> m;
    visit[n][0] = true;

    vector<ll2_ll>inputs;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        inputs.push_back({ {a,b},c });
    }

    vector<ll2_ll>arr;
    bool used[102] = {};
    for (int i = n - 1; i >= 0; i--) {
        int p = -1;
        for (int j = 0; j < n; j++) {
            if (used[j])continue;
            if (p == -1) {
                p = j;
                continue;
            }
            if (inputs[j].fi.se > inputs[p].fi.se) p = j;
        }
        if (p == -1)return -1;
        used[p] = true;
        arr.push_back(inputs[p]);
    }

    for (int i = 0; i < n; i++) {
        ll_ll w = arr[i].fi;
        ll cost = arr[i].se;
        for (int j = i; j >= 0; j--) {
            int days = n - j - 1;
            int ldays = days + 1;
            for (int k = m; k >= cost; k--) {
                int lk = k - cost;
                //cout << i << "에 " << days << "," << k << "/" << ldays << "," << lk << "옴.\n";
                if (visit[ldays][lk] == false)continue;
                visit[days][k] = true;
                dp[days][k] = max(dp[days][k], dp[ldays][lk] + w.fi + w.se * days);
                //cout << i << "에 " << days << "," << k << ":" << dp[days][k] << "!!\n";
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (visit[i][j] == false)continue;
            //cout << i << "," << j << ":" << dp[i][j] << "\n";
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
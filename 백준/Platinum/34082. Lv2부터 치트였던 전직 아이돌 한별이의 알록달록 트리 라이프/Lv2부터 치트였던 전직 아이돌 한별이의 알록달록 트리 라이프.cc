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
 
ll Custom_Mod;
// [0:빨,1:녹][부모꺼랑 다르나? -> 1][정점위치]
bool visit[2][2][300002];
ll dp[2][2][300002];
 
vector<ll>lines[300002];
 
vector<ll>now_mul_left[2][300002];
vector<ll>now_mul_right[2][300002];
 
ll pow_n(ll num, ll n) {
    if (n == 0)return 1;
    if (n == 1)return num;
    ll ans = pow_n(num, n / 2);
    ans *= ans;
    ans %= Custom_Mod;
    if (n % 2 == 1) {
        ans *= num;
        ans %= Custom_Mod;
    }
    return ans;
}
 
int one_line = 1;
ll dfs(bool is_green, bool diff, ll p, ll last_p) {
    if (visit[is_green][diff][p])
        return dp[is_green][diff][p];
 
    visit[is_green][diff][p] = true;
    if (p != one_line && lines[p].size() == 1)return dp[is_green][diff][p] = 1;
 
    ll sum = 1;
    //다른게 없을때
    if (diff) {
        for (int i = 0; i < lines[p].size(); i++) {
            ll next_p = lines[p][i];
            if (next_p == last_p) {
                continue;
            }
            ll h = dfs(is_green, false, next_p, p);
            sum *= h;
            sum %= Custom_Mod;
        }
 
        dp[is_green][diff][p] += sum;
        return dp[is_green][diff][p] %= Custom_Mod;
    }
 
    //하나라도 다른걸 설정할때
    //왼쪽 부터
    now_mul_left[is_green][p].resize(lines[p].size());
    now_mul_right[is_green][p].resize(lines[p].size());
    for (int i = 0; i < lines[p].size(); i++) {
        ll next_p = lines[p][i];
        if (next_p == last_p) {
            now_mul_left[is_green][p][i] = sum;
            continue;
        }
        ll h = dfs(is_green, false, next_p, p);
        sum *= h;
        sum %= Custom_Mod;
        now_mul_left[is_green][p][i] = sum;
    }
    //오른쪽 부터
    sum = 1;
    for (int i = int(lines[p].size()) - 1; i >= 0; i--) {
        ll next_p = lines[p][i];
        if (next_p == last_p) {
            now_mul_right[is_green][p][i] = sum;
            continue;
        }
        ll h = dfs(is_green, false, next_p, p);
        sum *= h;
        sum %= Custom_Mod;
        now_mul_right[is_green][p][i] = sum;
    }
 
    dp[is_green][diff][p] += sum;
    dp[is_green][diff][p] %= Custom_Mod;
 
    for (int i = 0; i < lines[p].size(); i++) {
        ll next_p = lines[p][i];
        if (next_p == last_p)
            continue;
 
        ll h = dfs(!is_green, true, next_p, p);
        if (i != 0) {
            h *= now_mul_left[is_green][p][i - 1];
            h %= Custom_Mod;
        }
        if (i + 1 < int(now_mul_right[is_green][p].size())) {
            h *= now_mul_right[is_green][p][i + 1];
            h %= Custom_Mod;
        }
 
        dp[is_green][diff][p] += h;
        dp[is_green][diff][p] %= Custom_Mod;
    }
 
    return dp[is_green][diff][p];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n >> Custom_Mod;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        lines[a].push_back(b);
        lines[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (lines[i].size() == 1) {
            one_line = i;
            break;
        }
    }
 
    ll sum = dfs(false, false, one_line, -1) + dfs(true, false, one_line, -1);
    sum %= Custom_Mod;
 
    cout << (pow_n(2, n) + (Custom_Mod - sum)) % Custom_Mod;
}

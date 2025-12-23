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
 
bool visit[21][1 << 21];
ll dp[21][1 << 21];
 
vector<ll>inputs;
 
ll n, m;
ll apown(const ll a, const ll len_n) {
    if (len_n == 0) return 1;
    if (len_n == 1) return a;
    ll h = apown(a, len_n / 2);
    h *= h;
    h %= MOD1;
    if (len_n % 2 == 1) {
        h *= a;
        h %= MOD1;
    }
    return h;
}
 
ll dfs(ll deep, ll state, ll sum) {
    if (deep > m)return 0;
    if (visit[deep][state])return dp[deep][state];
    //방문 처리하기, 이때 sum은 어차피 state처리하고 남은 위치를 다 더했을때 값이랑 같아 고려 x.
    visit[deep][state] = true;
 
    //현재 추첨에서 한별이가 걸릴때
    dp[deep][state] += (inputs[0] * apown(sum, MOD1 - 2)) % MOD1;
 
    //다른 친구들이 걸릴때 (한별이는 i=0)
    //apown(sum, MOD1 - 2)중복 많으니 ac받고 최적화 ㄱㄱ
    for (ll i = 1; i < n; i++) {
        //이전에 이미 처리한 친구 제외
        if ((state & (1ll << i)) != 0)continue;
        dp[deep][state] += (((inputs[i] * apown(sum, MOD1 - 2)) % MOD1) * dfs(deep + 1, (state + (1ll << i)), sum - inputs[i])) % MOD1;
        dp[deep][state] %= MOD1;
    }
 
    return dp[deep][state];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    ll sum = 0, w;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        inputs.push_back(w * w);
        sum += w * w;
    }
    cout << dfs(1, 0, sum);
}

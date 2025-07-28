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
 
bool used_dp[10005][10005];
int dp[10005][10005];
 
int m;
//{그룹의 앞 위치, 그룹의 뒷 위치}
vector<intint>arr;
 
int dfs(int arr_p, int left_p, int right_p) {
    if (arr_p + 1 == m)return max(0,right_p - left_p + 1);
    if (left_p > right_p)return 0;
    if (used_dp[left_p][right_p])return dp[left_p][right_p];
    used_dp[left_p][right_p] = true;
 
    //cout << arr_p << ":" << left_p << "~" << right_p << "중.\n";
    for (int now_p = left_p; now_p <= right_p; now_p++) {
        int next_left = now_p + 1;
        if (now_p < arr[arr_p].se) {
            next_left = arr[arr_p].se + (arr[arr_p].se - now_p);
        }
 
        int next_right = min(arr[arr_p + 2].fi - 1, 2 * arr[arr_p + 1].fi - now_p - 1);
 
        //cout << arr_p << "에서 " << now_p << "선택 후 다음 : {" << arr_p + 1<<"," << next_left << "," << next_right << "}\n";
 
        dp[left_p][right_p] += dfs(arr_p + 1, next_left, next_right);
        dp[left_p][right_p] %= MOD3;
    }
    return dp[left_p][right_p];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, w;
    cin >> n >> m >> k;
    int h = n / m;
    for (int i = 0; i < n; i++) {
        cin >> w;
        if (i % h == 0)arr.push_back({ w,0 });
        if ((i + 1) % h == 0)arr[arr.size() - 1].se = w;
    }
    arr.push_back({ k + 1,nINF });
    /*for (int i = 0; i < arr.size(); i++) {
        cout << i << ":" << arr[i].fi << "," << arr[i].se << "\n";
    }*/
 
    cout << dfs(0, 1, arr[1].fi - 1);
}

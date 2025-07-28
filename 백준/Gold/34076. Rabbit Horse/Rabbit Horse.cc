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
 
const string default_string = "RabbitHorse";
const string d_out_default_string = "RaitHorse";
 
inline ll cal(ll n) {
    ll ans = 1;
    ll h = n / 9;
    ll h2 = n % 9;
    for (int i = 0; i < 9; i++) {
        ll h3 = h;
        if (i < h2) {
            h3++;
        }
        ans *= h3;
    }
 
    return ans;
}
inline void print_ans(ll n, ll b_pinrt_count) {
    ll h = n / 9;
    ll h2 = n % 9;
    for (int i = 0; i < 9; i++) {
        if (i == 2) {
            while (b_pinrt_count-- > 0) {
                cout << "b";
            }
        }
 
        ll h3 = h;
        if (i < h2) {
            h3++;
        }
        while (h3--) {
            cout << d_out_default_string[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n <= 11) {
        for (int i = 0; i < n; i++) {
            cout << default_string[i];
        }
        return 0;
    }
 
    int left_count = n - 11;
    ll max_two = 1;
    ll max_ans = -1;
    for (int use_b = 2; use_b <= left_count + 2; use_b++) {
        ll h = cal(n - use_b) * (use_b * (use_b - 1)) / 2;
        if (max_ans < h) {
            max_two = use_b;
            max_ans = h;
        }
    }
    assert(max_two != 1);
 
    print_ans(n - max_two, max_two);
}

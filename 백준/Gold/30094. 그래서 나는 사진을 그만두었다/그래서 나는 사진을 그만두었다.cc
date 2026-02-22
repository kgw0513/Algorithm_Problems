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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll2_ll2>arr(n);
    map<ll, ll>cases;
    static int give_num = 0;
    for (ll2_ll2& w : arr) {
        give_num += 1;
        cin >> w.se.fi >> w.se.se;
        w.fi.fi = -w.se.fi + w.se.se;
        w.fi.se = give_num;
        cases[w.fi.fi] += 1;
        cases[w.fi.fi] %= MOD3;
    }
    sort(arr.begin(), arr.end());

    ll ans_cases = 1; //최소 최대 경우의 수는 같다.
    for (auto& h : cases) {
        for (ll i = 1; i <= h.se; i++) {
            ans_cases *= i;
            ans_cases %= MOD3;
        }
    }

    ll min_ans = 0;
    for (int i = 0; i < n; i++) {
        min_ans += arr[i].se.fi * i + arr[i].se.se * (n - i - 1);
    }

    cout << min_ans << " " << ans_cases << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].fi.se << " ";
    }
    cout << "\n";

    reverse(arr.begin(), arr.end());

    ll max_ans = 0;
    for (int i = 0; i < n; i++) {
        max_ans += arr[i].se.fi * i + arr[i].se.se * (n - i - 1);
    }

    cout << max_ans << " " << ans_cases << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].fi.se << " ";
    }
    cout << "\n";
}
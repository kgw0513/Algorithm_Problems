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

bool cmp(ll& a, ll& b) {
    return abs(a) < abs(b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t, a, b;
    cin >> n >> t;
    vector<ll>arr;
    vector<ll>brr;
    vector<ll>brr_sum;
    while (n-- > 0) {
        cin >> a >> b;
        arr.push_back(a);
        arr.push_back(-(b + 1));
    }
    sort(arr.begin(), arr.end(), cmp);
    {
        ll state = 0;
        ll last_p = 1;
        for (ll h : arr) {
            if (h > 0) {
                if (state == 0 && h - last_p > 0)brr.push_back(h - last_p);
                state++;
                continue;
            }
            state--;
            assert(h != 0 && state >= 0);
            if (state == 0)last_p = -h;
        }
        if (t + 1 - last_p > 0)brr.push_back(t + 1 - last_p);
        sort(brr.begin(), brr.end());

        if (brr.empty()) {
            cin >> n;
            while (n--) {
                cin >> a;
                cout << "0\n";
            }
            return 0;
        }

        brr_sum.resize(brr.size(), 0);
        brr_sum[int(brr.size()) - 1] = 1;
        ll counting = 0;
        for (int i = int(brr.size()) - 2; i >= 0; i--) {
            counting++;
            brr_sum[i] = brr_sum[i + 1] + counting * (brr[i + 1] - brr[i]) + 1;
        }
    }

    cin >> n;
    while (n--) {
        cin >> a;

        ll p = lower_bound(brr.begin(), brr.end(), a) - brr.begin();
        if (p >= brr.size()) {
            cout << "0\n";
            continue;
        }

        ll ans = brr_sum[p];
        ans += (int(brr.size()) - p) * (brr[p] - a);
        cout << ans << "\n";
    }
}
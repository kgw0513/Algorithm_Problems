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

//unordered_set, unordered_map 전용 (구조체로 쓸 경우 == operator도 필요)
//사용 예시 : unordered_set<intint,pair_hash> arr;
namespace std {
    struct default_hash {
        template <class T1>
        size_t operator()(const T1 n) const {
            hash<T1> a{}; size_t sa = a(n);
            return sa;
        }
    };
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> n) const {
            hash<T1> a{}; size_t sa = a(n.fi);
            hash<T2> b{}; size_t sb = b(n.se);
            return sa ^ sb;
        }
    };
}

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

void test() {
    ll n, q, k, m;
    cin >> n >> q;
    vector<ll>inputs(n);
    for (ll& w : inputs) {
        cin >> w;
    }
    sort(inputs.begin(), inputs.end());
    vector<ll>dp(n,0);
    dp[0] = inputs[0];
    for (int i = 1; i < n; i++) {
        dp[i] += dp[i - 1] + inputs[i];
    }

    //cout << "정렬 상태:\n";
    //for (int i = 0; i < inputs.size(); i++) {
    //    cout << inputs[i] << ",";
    //}
    //cout << "\n";

    while (q--) {
        cin >> k >> m;
        ll p = upper_bound(inputs.begin(), inputs.end(), k)-inputs.begin();
        p--;
        ll e = n - 1, s = p + 1;
        //cout << s << "~" << e << "위치 \n";
        ll find_p = -1;
        while (s <= e) {
            ll mid = (s + e) / 2;
            ll sum = n - mid;
            //0~p사이 k넘는 인풋 중앙과 비교해서 값 작거나 같은것들 갯수 찾아 더하기
            ll mink_p = upper_bound(inputs.begin(), inputs.begin() + p+1, 2*k-inputs[mid]) - inputs.begin();
            sum += mink_p;

            //cout << 2 * k - inputs[mid] << "위치를 통한.\n";
            //cout << mid << ":" << sum << "(" << mink_p << ")\n";
            if (sum <= m) {
                find_p = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        //cout << find_p << "위치임.\n";
        ll ans = 0;
        if (find_p == -1) {
            ll left_c = m;
            assert(left_c >= 1);
            left_c--;
            ans += dp[left_c];
        }
        else {
            ll back_c = (n - find_p);
            //cout << back_c << "개.\n";
            //cout << n - 1 << ":" << dp[n - 1] << "?\n";
            ans += 2 * k * back_c - (dp[n - 1] - (find_p > 0 ? dp[find_p - 1] : 0));
            //cout << ans << "중.\n";
            ll left_c = m - back_c;
            //cout << "앞 " << left_c << "개.\n";
            if (left_c > 0) {
                left_c--;
                //cout << 2 << ":" << dp[2] << "?\n";
                ans += dp[left_c];
            }
        }
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        test();
    }
}
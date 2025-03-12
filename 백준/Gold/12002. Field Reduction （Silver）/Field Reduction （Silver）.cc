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
constexpr unsigned long long MOD1 = 1000000363;
constexpr unsigned long long MOD2 = 1000000007;
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

bool cmp1(intint& a, intint& b) {
    return a.fi > b.fi;
}
bool cmp2(intint& a, intint& b) {
    return a.fi < b.fi;
}
bool cmp3(intint& a, intint& b) {
    return a.se > b.se;
}
bool cmp4(intint& a, intint& b) {
    return a.se < b.se;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<intint>arr;
    deque<intint>brr;
    int n,a,b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        arr.push_back({ a,b });
    }
    sort(arr.begin(), arr.end(),cmp1);
    for (int i = 0; i < 3 && arr.size(); i++) {
        brr.push_back(arr.front());
        arr.pop_front();
    }
    sort(arr.begin(), arr.end(), cmp2);
    for (int i = 0; i < 3 && arr.size(); i++) {
        brr.push_back(arr.front());
        arr.pop_front();
    }
    sort(arr.begin(), arr.end(), cmp3);
    for (int i = 0; i < 3 && arr.size(); i++) {
        brr.push_back(arr.front());
        arr.pop_front();
    }
    sort(arr.begin(), arr.end(), cmp4);
    for (int i = 0; i < 3 && arr.size(); i++) {
        brr.push_back(arr.front());
        arr.pop_front();
    }

    intint x_len = { INF,-INF }, y_len = { INF,-INF };
    while (arr.size()) {
        x_len.fi = min(x_len.fi, arr.front().fi);
        x_len.se = max(x_len.se, arr.front().fi);
        y_len.fi = min(y_len.fi, arr.front().se);
        y_len.se = max(y_len.se, arr.front().se);
        arr.pop_front();
    }

    int ans = INF;
    for (int i = 0; i < brr.size(); i++) {
        for (int j = i + 1; j < brr.size(); j++) {
            for (int k = j + 1; k < brr.size(); k++) {
                intint ans_x_len = x_len, ans_y_len = y_len;
                for (int l = 0; l < brr.size(); l++) {
                    if (i == l || j == l || k == l)
                        continue;

                    ans_x_len.fi = min(ans_x_len.fi, brr[l].fi);
                    ans_x_len.se = max(ans_x_len.se, brr[l].fi);
                    ans_y_len.fi = min(ans_y_len.fi, brr[l].se);
                    ans_y_len.se = max(ans_y_len.se, brr[l].se);
                }
                ans = min(ans, (ans_x_len.se - ans_x_len.fi) * (ans_y_len.se - ans_y_len.fi));
            }
        }
    }
    cout << ans;
}
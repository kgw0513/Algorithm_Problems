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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        double a, b;
        int k;
        cin >> a >> b >> k;
        double ans = (a + b) - sqrt(a * a + b * b);
        ans /= 2.0;
        double cal_ra = ans;
        double cal_rb = ans;
        double cal_r = ans;
        double ha = ans * ans + (a - ans) * (a - ans);
        double hb = ans * ans + (b - ans) * (b - ans);
        ha = sqrt(ha);
        hb = sqrt(hb);
        double h = sqrt(2) * ans;
        while (--k > 0) {
            double new_ra = cal_ra * ha - cal_ra * cal_ra;
            new_ra /= (cal_ra + ha);
            double new_rb = cal_rb * hb - cal_rb * cal_rb;
            new_rb /= (cal_rb + hb);
            double new_r = cal_r * h - cal_r * cal_r;
            new_r /= (cal_r + h);
            //cout << new_ra << "," << new_rb << "," << new_r << "발견.\n";
            if (new_ra >= new_rb && new_ra >= new_r) {
                ha -= cal_ra;
                ha -= new_ra;
                cal_ra = new_ra;
                ans = new_ra;
            }
            else if (new_rb >= new_ra && new_rb >= new_r) {
                hb -= cal_rb;
                hb -= new_rb;
                cal_rb = new_rb;
                ans = new_rb;
            }
            else {
                h -= cal_r;
                h -= new_r;
                cal_r = new_r;
                ans = new_r;
            }
        }
        cout.precision(12);
        //cout << PI<<"*"<<ans * ans << "중간 계산\n";
        cout << ans * ans * PI << "\n";
    }
}
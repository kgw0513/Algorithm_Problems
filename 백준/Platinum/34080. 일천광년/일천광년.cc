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
 
inline ll gcd(ll a, ll b) {
    while (a % b != 0) {
        ll h = a % b;
        a = b;
        b = h;
    }
    return b;
}
 
//{{x가 되는 수, n수},해당 위치 값}
inline ll2_ll cal(const ll& x, const ll& y, ll n) {
    ll h_x = x * INF;
    return { { (INF - (h_x - y * n) / x),n } ,(h_x - y * n) % x };
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        bool is_swap = false;
        if (x < y) {
            swap(x, y);
            is_swap = true;
        }
        if (x == y || n == 1) {
            if (n % 2 == 0) {
                cout << "1\n" << n / 2 << " " << x + y << "\n";
            }
            else {
                if (is_swap)cout << "2\n" << n / 2 << " " << y << "\n" << n / 2 + 1 << " " << x << "\n";
                else cout << "2\n" << n / 2 << " " << x << "\n" << n / 2 + 1 << " " << y << "\n";
            }
            continue;
        }
        ll h = gcd(x, y);
 
        ll row_x = y / h;
 
        ll circle_x = x / h + row_x;
        ll counting = n / circle_x;
        if (n % circle_x == 0) {
            if (is_swap) {
                cout << "1\n" << n - row_x * counting << " " << x + y << "\n";
            }
            else {
                cout << "1\n" << row_x * counting << " " << x + y << "\n";
            }
            continue;
        }
        ll left_n = n % circle_x;
        cout << "2\n"; //확정
 
        ll s = 1, e = x / h - 1, check_ans = 0;
        while (s <= e) {
            ll mid = (s + e) / 2;
            ll2_ll h = cal(x, y, mid);
            if (h.fi.fi + h.fi.se <= left_n) {
                check_ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
 
        //cout << check_ans << "/" << cal(x, y, check_ans).fi.fi << "+" << cal(x, y, check_ans).fi.se << " == " << left_n << "\n";
        //cout << cal(x, y, check_ans).se << "라는 나머지.\n";
        ll move_left, move_right;
        ll left_value, right_value;
        if (check_ans == 0) {
            left_value = x;
            right_value = y;
 
            if (is_swap) {
                move_right = row_x * counting;
                move_right = n - move_right;
                move_left = move_right - 1;
                swap(left_value, right_value);
            }
            else {
                move_left = row_x * counting;
                move_right = move_left + 1;
            }
        }
        else if (cal(x, y, check_ans).fi.fi + cal(x, y, check_ans).fi.se != left_n) {
            right_value = y - cal(x, y, check_ans).se;
            left_value = x + y - right_value;
 
            if (is_swap) {
                move_right = row_x * counting + cal(x, y, check_ans).fi.fi;
                move_right = n - move_right;
                move_left = move_right - 1;
                swap(left_value, right_value);
            }
            else {
                move_left = row_x * counting + cal(x, y, check_ans).fi.fi;
                move_right = move_left + 1;
            }
        }
        else {
            left_value = cal(x, y, check_ans).se;
            right_value = y + (x - cal(x, y, check_ans).se);
 
            if (is_swap) {
                move_right = row_x * counting + (cal(x, y, check_ans).fi.fi - 1);
                move_right = n - move_right;
                move_left = move_right - 1;
                swap(left_value, right_value);
            }
            else {
                move_left = row_x * counting + (cal(x, y, check_ans).fi.fi - 1);
                move_right = move_left + 1;
            }
        }
 
        cout << move_left << " " << left_value << "\n";
        cout << move_right << " " << right_value << "\n";
    }
}

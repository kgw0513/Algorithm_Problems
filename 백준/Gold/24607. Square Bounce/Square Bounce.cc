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
#include <cassert>
#pragma warning(disable:4996)
#define fi first
#define se second
#define print_end "\n"
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
typedef pair<sh_sh, sh_sh>sh2_sh2;
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

ll a, b, n;

ll gcd(ll a, ll b) {
    while (a % b != 0) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return b;
}

void print_ans(ll swap_x, ll swap_y,bool x_end) {
    bool is_x_flip = (swap_x % 2 == 1);
    bool is_y_flip = (swap_y % 2 == 1);
    if (x_end) {
        //x축 출력
        if (is_x_flip)cout << "1 1 ";
        else cout << "-1 1 ";

        //y축 출력
        ll h1 = a * (2*swap_x-1) + a;
        ll h2 = b;
        while (h2 < h1) {
            h1 -= 2 * b;
        }
        if (h1 == 0) {
            cout << "0 1";
            return;
        }
        if (is_y_flip) {
            h1 *= -1;
        }
        ll h3 = gcd(abs(h1), abs(h2));
        h1 /= h3;
        h2 /= h3;
        cout << h1 << " " << h2;
        return;
    }
    else {
        //x축 출력
        ll h1= b * (2 * swap_y - 1) - a;
        ll h2 = a;
        while (h2 < h1) {
            h1 -= 2 * a;
        }
        if (h1 == 0) {
            cout << "0 1";
        }
        else {
            if (is_x_flip) {
                h1 *= -1;
            }
            ll h3 = gcd(abs(h1), abs(h2));
            h1 /= h3;
            h2 /= h3;
            cout << h1 << " " << h2;
        }
        cout << " ";

        //y축 출력
        if (is_y_flip)cout << "1 1";
        else cout << "-1 1";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> n;
    n++;
    {
        ll s = 1, e = n;
        while (s <= e) {
            ll mid = (s + e) / 2;

            ll swap_x = mid;
            ll hu = (a * (mid * 2 - 1) + a);
            ll hd = b;
            ll swap_y = (hu / hd + 1) / 2;
            ll sum = swap_x + swap_y;
            if (sum == n) { //갯수가 동일하면 x충돌로 끝이라는 거니 바로 답 처리
                print_ans(swap_x, swap_y, true);
                return 0;
            }
            else if (sum < n) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
    }
    {
        ll s = 1, e = n;
        while (s <= e) {
            ll mid = (s + e) / 2;

            ll swap_y = mid;
            ll hu = (b * (mid * 2 - 1) - a);
            ll hd = a;
            ll swap_x = (hu / hd + 1) / 2;
            ll sum = swap_y + swap_x;
            if (sum == n) { //갯수가 동일하면 y충돌로 끝이라는 거니 바로 답 처리
                print_ans(swap_x, swap_y, false);
                return 0;
            }
            else if (sum < n) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
    }

    //둘다 없으면 잘못 짠듯...
    return -1;
}
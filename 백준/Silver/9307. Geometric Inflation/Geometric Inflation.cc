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

void print_money(ll a) {
    ll sosu = a % 100;
    a /= 100;
    vector<int>arr;
    while (a > 0) {
        arr.push_back(a % 1000);
        a /= 1000;
    }

    if (arr.empty()) {
        cout << "0";
    }
    else {
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (i == arr.size() - 1)cout << arr[i];
            else {
                if (arr[i] >= 100)cout << arr[i];
                else if (arr[i] >= 10)cout << "0" << arr[i];
                else cout << "00" << arr[i];
            }
            if (i != 0)cout << ",";
        }
    }
    cout << ".";
    if (sosu >= 10)cout << sosu;
    else cout << "0" << sosu;
    cout << "\n";
}
bool test() {
    double ha, hb, hc;
    ll n;
    cin >> ha;
    if (ha == -1)return false;

    cin >> hb >> hc >> n;

    ll a = ha * 1000;
    ll b = hb * 1000;
    ll c = hc * 1000;

    cout << "Month " << n << " cost: $";
    if (n == 1) {
        print_money(a / 10);
        return true;
    }

    if (n == 2) {
        print_money(b / 10);
        return true;
    }
    n -= 3;
    while (n > 0) {
        n--;
        ll d = a * b / c;
        ll hd = d % 10;
        d /= 10;
        d *= 10;
        if (hd >= 5)d += 10;
        a = b;
        b = c;
        c = d;
    }

    print_money(c / 10);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        if (!test())break;
    }
}
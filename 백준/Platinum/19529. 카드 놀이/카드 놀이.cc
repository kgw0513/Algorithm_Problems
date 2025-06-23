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

int visit[30001];

static int visit_count = 0;
void proc(ll n, ll x) {
    visit_count++;
    ll b = n * (n + 1) / 2;
    b -= x;
    if (b % 2 != 0) {
        cout << "NO\n";
        return;
    }
    b /= 2;
    ll a = b + x;
    deque<ll>arr;
    deque<ll>brr;
    ll a_have = n / 2;
    ll sum = a_have * (a_have + 1) / 2;
    if (n % 2 == 1) {
        a_have = n / 2 + 1;
        sum = a_have * (a_have + 1) / 2;
        //cout << a_have << "," << sum << "개정.\n";
    }
    //cout << a << "/" << sum << "=>\n";
    ll left = a - sum;
    //cout << left << "치워야함.\n";
    if (n % 2 == 1) {
        for (int i = a_have; i >= 2; i--) {
            ll h = max(min(left, a_have - 1), 0ll);
            visit[i + h] = visit_count;
            //cout << "a:" << i + h << "기록.\n";
            left -= h;
        }
    }
    else {
        if (left < a_have) {
            cout << "NO\n";
            return;
        }
        left -= a_have;
        for (int i = a_have + 1; i >= 2; i--) {
            ll h = max(min(left, a_have - 1), 0ll);
            visit[i + h] = visit_count;
            left -= h;
        }
    }

    if (left != 0) {
        cout << "NO\n";
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (visit[i] == visit_count)arr.push_back(i);
        else brr.push_back(i);
    }
    cout << "YES\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
        if (i < brr.size())cout << brr[i] << " ";
    }
    cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        proc(a, b);
    }
}
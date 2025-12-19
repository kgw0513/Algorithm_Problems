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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

struct cmp {
    bool operator()(ll2_ll& a, ll2_ll& b) {
        return a.se > b.se;
    }
};

int Union[10002];
int Find(int n) {
    if (n == Union[n])return n;
    return Union[n] = Find(Union[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, t, a, b, c;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        Union[i] = i;
    }
    priority_queue<ll2_ll,vector<ll2_ll>,cmp>inputs;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        inputs.push({ {a,b},c });
    }
    ll sum = 0;
    for (ll i = 1; i < n; i++) {
        sum += t * (i-1);
    }
    while (inputs.size()) {
        a = inputs.top().fi.fi;
        b = inputs.top().fi.se;
        c = inputs.top().se;
        inputs.pop();

        a = Find(a);
        b = Find(b);
        if (a == b)continue;
        if (a > b)swap(a, b);
        Union[a] = b;
        sum += c;
    }
    cout << sum;
}
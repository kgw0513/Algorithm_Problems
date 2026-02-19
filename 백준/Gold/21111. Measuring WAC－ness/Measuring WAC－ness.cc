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

ll A[200002];
ll A_SUM[200002];

ll W[200002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    string w;
    cin >> n >> k >> w;

    ll C_count = 0; //c0
    ll A_count = 0; //a0
    ll A_double = 0; //A갯수
    ll W_count = 0; //w0
    ll W_double = 0;
    ll WA_double = 0; //w갯수
    for (int i = n - 1; i >= 0; i--) {
        if (w[i] == 'C') {
            C_count++;
            C_count %= MOD3;
        }
        else if (w[i] == 'A') {
            A_count += C_count;
            A_count %= MOD3;
            A_double++;
            A_double %= MOD3;
        }
        else if (w[i] == 'W') {
            W_count += A_count;
            W_count %= MOD3;
            W_double ++;
            W_double %= MOD3;
            WA_double +=A_double;
            WA_double %= MOD3;
        }
    }

    A[0] = A_count;
    A_SUM[0] = A_count;
    ll ans = W_count;
    W[0] = W_count;
    for (int i = 1; i < k; i++) {
        A[i] = (A[i - 1] + A_double * C_count)%MOD3;
        A_SUM[i] = A[i] + A_SUM[i - 1];
        A_SUM[i] %= MOD3;
        ll h1 = A_SUM[i - 1] * W_double;
        h1 %= MOD3;

        ll h2 = WA_double * C_count;
        h2 %= MOD3;
        h2 *= i;
        h2 %= MOD3;
        //cout << A_SUM[i - 1] << "*" << W_double << "+" << "(" << W[0] << "+" << i << "*" << WA_double << "*" << C_count << ")" << " =>";
        W[i] = (h1+(W[0]+h2)) % MOD3;
        //cout << W[i] << "중.\n";
        ans += W[i];
        ans %= MOD3;
    }
    cout << ans % MOD3;
}
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

bool is_check_same[1000002];
intint check_same[1000002];

int visit_num = 0;
int already_visit[1000002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int& w : arr) {
        cin >> w;
    }

    //sqrt(n)으로 a+b 범위내 되는 구간 찾기
    //즉 0<=a+b<=sqrt(n)
    for (int sum_state = 0; sum_state <= sqrt(n); sum_state++) {
        fill(is_check_same, is_check_same + 1000002, false);
        ++visit_num;
        for (int a = 0; a < n; a++) {
            int b = sum_state - a + n;
            b %= n;
            if (already_visit[b])break;
            already_visit[a] = visit_num;
            if (is_check_same[(arr[a] + arr[b]) % n]) {
                cout << "Ja\n";
                cout << a + 1 << " " << b + 1 << " " << check_same[(arr[a] + arr[b]) % n].fi << " " << check_same[(arr[a] + arr[b]) % n].se << "\n";
                return 0;
            }
            is_check_same[(arr[a] + arr[b]) % n] = true;
            check_same[(arr[a] + arr[b]) % n] = { a + 1,b + 1 };
        }
    }
    //cout << "여긴 실패.\n";
    for (int a = 0; a <= sqrt(n); a++) {
        for (int b = a; b < n; b++) {
            int c1 = (a - 1 + n) % n;
            int d1 = (b + 1) % n;
            if (!((a == c1 && b == d1) || (b == c1 && a == d1))) {
                if ((arr[a] + arr[b]) % n == (arr[c1] + arr[d1]) % n) {
                    cout << "Ja\n";
                    cout << a + 1 << " " << b + 1 << " " << c1 + 1 << " " << d1 + 1 << "\n";
                    return 0;
                }
            }
            int c2 = (a + 1) % n;
            int d2 = (b - 1 + n) % n;
            if (!((a == c2 && b == d2) || (b == c2 && a == d2))) {
                if ((arr[a] + arr[b]) % n == (arr[c2] + arr[d2]) % n) {
                    cout << "Ja\n";
                    cout << a + 1 << " " << b + 1 << " " << c2 + 1 << " " << d2 + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    return -1;
}
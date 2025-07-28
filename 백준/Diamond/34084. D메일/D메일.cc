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
 
int dp[1 << 21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, t, w;
    cin >> n >> t;
 
    int n_pow = 1 << n;
    for (int i = 0; i < n_pow; i++) {
        int state = 0;
        for (int j = 0; j < n / 2; j++) {
            if (i & (1 << (j * 2)) && i & (1 << (j * 2 + 1)))state++;
        }
        //2칸씩 나눠서 11의 갯수의 홀짝성 저장. 만약 n이 홀수라면 마지막은 1개로 구분.
        if (n % 2 && (i & (1 << (n - 1))))state++;
        cout << (dp[i] = (state % 2));
    }
    cout << "\n" << flush;
 
    while (t--) {
        cout << "? 0\n" << flush;
        int first_state;
        cin >> first_state; //현재 홀짝 상태
        int last_say = 0;
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            int c1 = i * 2;
            int c2 = i * 2 + 1;
 
            int c1_say = 1 << c1;
            c1_say += last_say;
            last_say = 1 << c1;
            cout << "? " << c1_say << "\n" << flush;
            cin >> w;
            if (first_state != w)ans += (1 << c2);
 
            int c2_say = 1 << c2;
            c2_say += last_say;
            last_say = 1 << c2;
            cout << "? " << c2_say << "\n" << flush;
            cin >> w;
            if (first_state != w)ans += (1 << c1);
        }
        if (n % 2) {
            //만약 홀수개로 끝나면 마지막 1개는 구분을 위해 맨 앞 비트의 자리만 보고 맞춰야 해서 그동안 모은거 xor해서 보기
            cout << "? " << (ans ^ last_say) << "\n" << flush;
            cin >> w;
            if (w)ans += (1 << (n - 1));
        }
        cout << "! " << ans << "\n" << flush;
    }
}

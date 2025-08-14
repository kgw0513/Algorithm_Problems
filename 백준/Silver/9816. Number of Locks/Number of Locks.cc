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

//[3차이 생기면 1][n][state][마지막숫자]
ll arr[2][17][16][16];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    arr[0][1][1][1] = 1;
    arr[0][1][2][2] = 1;
    arr[0][1][4][2] = 1;
    arr[0][1][8][8] = 1;
    for (int n = 2; n < 17; n++) {
        for (int last_state = 1; last_state < 16; last_state++) {
            //3 완성 못했을때
            for (int last_num = 1; last_num < 16; last_num <<= 1) {
                for (int now_num = 1; now_num < 16; now_num <<= 1) {
                    if (last_num + now_num == 9) {
                        arr[1][n][last_state | now_num][now_num] +=
                            arr[0][n - 1][last_state][last_num];
                    }
                    else {
                        arr[0][n][last_state | now_num][now_num] +=
                            arr[0][n - 1][last_state][last_num];
                    }
                }
            }

            //이미 3완성 했을때
            for (int last_num = 1; last_num < 16; last_num <<= 1) {
                for (int now_num = 1; now_num < 16; now_num <<= 1) {
                    arr[1][n][last_state | now_num][now_num] +=
                        arr[1][n - 1][last_state][last_num];
                }
            }
        }
    }
    int w;
    while (1) {
        cin >> w;
        if (w == -1)break;
        ll ans = 0;
        for (int state = 1; state < 16; state++) {
            if ((state & 1) == 0 || (state & 8) == 0)continue;
            if ((state & 2) == 0 && (state & 4) == 0)continue;
            ans += arr[1][w][state][1];
            ans += arr[1][w][state][2];
            ans += arr[1][w][state][4];
            ans += arr[1][w][state][8];
        }
        cout << w << ": " << ans << "\n";
    }
}
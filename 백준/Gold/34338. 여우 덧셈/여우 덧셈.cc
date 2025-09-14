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

//[자릿수][S위치][N위치]
int dp[11][1002][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //dp 초기화
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 1002; j++) {
            for (int k = 0; k < 1002; k++) {
                dp[i][j][k] = nINF;
            }
        }
    }

    string S, N;
    cin >> S >> N;
    dp[10][0][0] = 0;
    for (int S_i = 0; S_i < S.size(); S_i++) {
        for (int N_i = 0; N_i < N.size(); N_i++) {
            for (int digit = 0; digit <= 10; digit++) {
                if (dp[digit][S_i][N_i] >= nINF)continue;

                //있는 숫자 더하기
                int new_digit = (digit + (S[S_i] - '0')) % 10;
                dp[new_digit][S_i + 1][N_i] = min(dp[new_digit][S_i + 1][N_i], dp[digit][S_i][N_i]);

                //만약 있는 숫자를 더했는데 현재 S_i와 같다면 다음걸로 넘겨주기도 하기
                if (new_digit == (N[N_i] - '0')) {
                    dp[10][S_i + 1][N_i + 1] = min(dp[10][S_i + 1][N_i + 1], dp[digit][S_i][N_i]);
                }

                //0으로 바꾸기
                dp[digit][S_i + 1][N_i] = min(dp[digit][S_i + 1][N_i], dp[digit][S_i][N_i] + 1);

                //만약 0으로 바꾸었는데 현재 S_i와 같다면 다음걸로 넘겨주도록 하기
                if ((digit % 10) == (N[N_i] - '0')) {
                    dp[10][S_i + 1][N_i + 1] = min(dp[10][S_i + 1][N_i + 1], dp[digit][S_i][N_i] + 1);
                }
            }
        }
    }
    cout << (dp[10][S.size()][N.size()] < nINF ? dp[10][S.size()][N.size()] : -1);
}
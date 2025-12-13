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

//[a좌표][b좌표][c좌표]
int dp[16][16][16][16][16][16];
char state[16][16];

intint dxdy[5] = { {-1,0},{1,0},{0,-1},{0,1},{0,0} };

inline bool bIsBlock(intint p) {
    return state[p.fi][p.se] == '#';
}
inline bool bIsCross(intint la, intint a, intint lb=intint({-1,-2}), intint b = intint({ -2,-3 }), intint lc = intint({ -3,-4 }), intint c = intint({ -4,-5 })) {
    return a == b || b == c || a == c||la == b && a == lb || la == c && a == lc||lb == c && b == lc;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    while (1) {
        for (int a = 0; a < 16; a++) {
            for (int b = 0; b < 16; b++) {
                for (int c = 0; c < 16; c++) {
                    for (int d = 0; d < 16; d++) {
                        for (int e = 0; e < 16; e++) {
                            for (int f = 0; f < 16; f++) {
                                dp[a][b][c][d][e][f] = nINF;
                            }
                        }
                    }
                }
            }
        }
        cin >> m >> n >> k;
        if (n == 0)break;
        vector<intint>first_state(3, { 0,0 });
        vector<intint>last_state(3, { 0,0 });
        cin.ignore();
        cin.ignore();
        string w;
        for (int i = 0; i < n; i++) {
            //cout << i << "번째 줄\n";
            getline(cin, w);
            for (int j = 0; j < m; j++) {
                state[i][j] = w[j];
                //cout << i << "," << j << ":" << state[i][j] << "\n";
                if (state[i][j] >= 'A' && state[i][j] <= 'C') {
                    first_state[state[i][j] - 'A'] = { i,j };
                    state[i][j] = '.';
                }
                else if (state[i][j] >= 'a' && state[i][j] <= 'c') {
                    last_state[state[i][j] - 'a'] = { i,j };
                    state[i][j] = '.';
                }
            }
        }

        queue<vector<intint>>arr;
        arr.push(first_state);
        dp[first_state[0].fi][first_state[0].se][first_state[1].fi][first_state[1].se][first_state[2].fi][first_state[2].se] = 0;

        while (arr.size()) {
            intint a = arr.front()[0];
            intint b = arr.front()[1];
            intint c = arr.front()[2];
            arr.pop();
            for (intint dxdy_a : dxdy) {
                intint new_a = { a.fi + dxdy_a.fi,a.se + dxdy_a.se };
                if (bIsBlock(new_a))continue;
                if (k == 1) {
                    if (bIsCross(a, new_a))continue;
                    if (dp[new_a.fi][new_a.se][b.fi][b.se][c.fi][c.se] != nINF)continue;
                    dp[new_a.fi][new_a.se][b.fi][b.se][c.fi][c.se] = dp[a.fi][a.se][b.fi][b.se][c.fi][c.se] + 1;
                    arr.push({ new_a,b,c });
                    continue;
                }
                for (intint dxdy_b : dxdy) {
                    intint new_b = { b.fi + dxdy_b.fi,b.se + dxdy_b.se };
                    if (bIsBlock(new_b))continue;
                    if (k == 2) {
                        if (bIsCross(a, new_a,b,new_b))continue;
                        if (dp[new_a.fi][new_a.se][new_b.fi][new_b.se][c.fi][c.se] != nINF)continue;
                        dp[new_a.fi][new_a.se][new_b.fi][new_b.se][c.fi][c.se] = dp[a.fi][a.se][b.fi][b.se][c.fi][c.se] + 1;
                        arr.push({ new_a,new_b,c });
                        continue;
                    }
                    for (intint dxdy_c : dxdy) {
                        intint new_c = { c.fi + dxdy_c.fi,c.se + dxdy_c.se };
                        if (bIsBlock(new_c))continue;
                        if (k == 3) {
                            if (bIsCross(a, new_a, b, new_b,c,new_c))continue;
                            if (dp[new_a.fi][new_a.se][new_b.fi][new_b.se][new_c.fi][new_c.se] != nINF)continue;
                            dp[new_a.fi][new_a.se][new_b.fi][new_b.se][new_c.fi][new_c.se] = dp[a.fi][a.se][b.fi][b.se][c.fi][c.se] + 1;
                            arr.push({ new_a,new_b,new_c });
                            continue;
                        }
                    }
                }
            }
        }

        if (dp[last_state[0].fi][last_state[0].se][last_state[1].fi][last_state[1].se][last_state[2].fi][last_state[2].se] == nINF)return -1;
        cout << dp[last_state[0].fi][last_state[0].se][last_state[1].fi][last_state[1].se][last_state[2].fi][last_state[2].se] << "\n";
    }
}
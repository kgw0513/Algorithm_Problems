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

bool dp[152][152][4][1502]; //[n][m][dxdy상태][왼쪽 회전 수]
char state[152][152];

int arrow2num[26]; //dxdy 정보 들어있음

intint dxdy[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    arrow2num['U' - 'A'] = 0;
    arrow2num['R' - 'A'] = 1;
    arrow2num['D' - 'A'] = 2;
    arrow2num['L' - 'A'] = 3;

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> state[i][j];
        }
    }

    //문제점으로 갔던길 돌아오면 화살표 바꾼상태를 유지 못하는건데 딱히 상관없는게 최단거리 찾는거라 그 길은 어차피 느림
    deque<int2_int2>arr;
    arr.push_back({ {1,1},{arrow2num[state[1][1] - 'A'],0} });
    dp[1][1][arrow2num[state[1][1] - 'A']][0] = true;
    for (int right_time = 0; right_time <= k && !arr.empty(); right_time++) {
        int size = arr.size();
        while (size--) {
            intint now_p = arr.front().fi;
            int dxdy_state = arr.front().se.fi;
            int left_turn = arr.front().se.se;
            arr.pop_front();

            //cout << right_time << ":" << now_p.fi << "," << now_p.se << "/" << dxdy_state << "/" << left_turn << "상태.\n";
            //현재 화살표 그대로 따라가기 (0-1 bfs 앞 넣기)
            {
                intint new_p = { now_p.fi + dxdy[dxdy_state].fi,now_p.se + dxdy[dxdy_state].se };
                if (new_p.fi >= 1 && new_p.fi <= n && new_p.se >= 1 && new_p.se <= m) {
                    if (!dp[new_p.fi][new_p.se][arrow2num[state[new_p.fi][new_p.se] - 'A']][left_turn]) {
                        dp[new_p.fi][new_p.se][arrow2num[state[new_p.fi][new_p.se] - 'A']][left_turn] = true;
                        arr.push_front({ new_p,{arrow2num[state[new_p.fi][new_p.se] - 'A'],left_turn} });
                        size++;
                    }
                }
            }

            //왼쪽 회전하기 (0-1 bfs 앞 넣기)
            {
                intint new_p = now_p;
                int new_left_turn = left_turn + 1;
                int new_dxdy_state = (dxdy_state + 3) % 4;
                if (new_left_turn <= k && !dp[new_p.fi][new_p.se][new_dxdy_state][new_left_turn] &&
                    new_p.fi >= 1 && new_p.fi <= n && new_p.se >= 1 && new_p.se <= m) {
                    dp[new_p.fi][new_p.se][new_dxdy_state][new_left_turn] = true;
                    arr.push_front({ new_p,{new_dxdy_state,new_left_turn} });
                    size++;
                }
            }

            //오른쪽 회전하기 (0-1 bfs 뒤 넣기)
            if (right_time + 1 <= k) {
                intint new_p = now_p;
                int new_left_turn = left_turn;
                int new_dxdy_state = (dxdy_state + 1) % 4;
                if (new_left_turn <= k && !dp[new_p.fi][new_p.se][new_dxdy_state][new_left_turn] &&
                    new_p.fi >= 1 && new_p.fi <= n && new_p.se >= 1 && new_p.se <= m) {
                    dp[new_p.fi][new_p.se][new_dxdy_state][new_left_turn] = true;
                    arr.push_back({ new_p,{new_dxdy_state,new_left_turn} });
                }
            }
        }
    }

    bool is_can = false;
    for (int i = 0; i < 4 && !is_can; i++) {
        for (int j = 0; j < 1502 && !is_can; j++) {
            if (dp[n][m][i][j]) {
                is_can = true;
                break;
            }
        }
    }

    if (is_can)cout << "Yes";
    else cout << "No";
}
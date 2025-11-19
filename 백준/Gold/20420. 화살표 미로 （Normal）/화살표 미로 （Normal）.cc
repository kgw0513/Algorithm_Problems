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
typedef pair<sh_sh, sh_sh>sh2_sh2;
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

short dp[152][152][1502]; //[n][m][왼쪽 회전 수] = 최소 right회전값
char state[152][152];

int arrow2num[26]; //dxdy 정보 들어있음

intint dxdy[4] = { {-1,0},{0,1},{1,0},{0,-1} };

struct cmp {
    bool operator()(sh2_sh2& a, sh2_sh2& b) {
        return a.se.se > b.se.se;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 152; i++) {
        for (int j = 0; j < 152; j++) {
            for (int k = 0; k < 1502; k++) {
                dp[i][j][k] = 30000;
            }
        }
    }
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

    //{위치,{왼쪽 회전값,오른쪽 회전값}}
    priority_queue<sh2_sh2, vector<sh2_sh2>, cmp>arr;
    arr.push({ {1,1},{0,0} });
    dp[1][1][0] = 0;
    while (!arr.empty()) {
        intint now_p = arr.top().fi;
        int left_turn = arr.top().se.fi;
        int right_turn = arr.top().se.se;
        arr.pop();
        if (dp[now_p.fi][now_p.se][left_turn] != right_turn)continue;
        int now_dxdy = arrow2num[state[now_p.fi][now_p.se] - 'A'];

        //왼쪽 a번 회전후 이동할때(0<=a<4)
        for (int a = 0; a < 4; a++) {
            int new_dxdy = (now_dxdy + 4 - a) % 4;
            intint new_p = { now_p.fi + dxdy[new_dxdy].fi,now_p.se + dxdy[new_dxdy].se };
            int new_left_turn = left_turn + a;
            int new_right_turn = right_turn;
            if (new_left_turn <= k && new_right_turn <= k && 1 <= new_p.fi && new_p.fi <= n && 1 <= new_p.se && new_p.se <= m
                && dp[new_p.fi][new_p.se][new_left_turn] > new_right_turn) {
                arr.push({ new_p,{new_left_turn,new_right_turn} });
                dp[new_p.fi][new_p.se][new_left_turn] = new_right_turn;
            }
        }

        //오른쪽 a번 회전후 이동할때(1<=a<4)
        for (int a = 1; a < 4; a++) {
            int new_dxdy = (now_dxdy + a) % 4;
            intint new_p = { now_p.fi + dxdy[new_dxdy].fi,now_p.se + dxdy[new_dxdy].se };
            int new_left_turn = left_turn;
            int new_right_turn = right_turn + a;
            if (new_left_turn <= k && new_right_turn <= k && 1 <= new_p.fi && new_p.fi <= n && 1 <= new_p.se && new_p.se <= m
                && dp[new_p.fi][new_p.se][new_left_turn] > new_right_turn) {
                arr.push({ new_p,{new_left_turn,new_right_turn} });
                dp[new_p.fi][new_p.se][new_left_turn] = new_right_turn;
            }
        }
    }

    bool is_can = false;
    for (int i = 0; i <= k; i++) {
        if (dp[n][m][i] <= k) {
            is_can = true;
            break;
        }
    }

    if (is_can)cout << "Yes";
    else cout << "No";
}
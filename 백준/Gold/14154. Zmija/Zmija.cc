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

int move_lines[26];
deque<intint>lines[26];

char state[1002][1002];
bool visit[1002][1002];
//상우하좌
intint dxdy[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int give_dxdy[3] = { 0,1,-1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            state[i][j] = '#';
            if (1 <= i && i <= n && 1 <= j && j <= n)
                cin >> state[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ('A' <= state[i][j] && state[i][j] <= 'Z') {
                char h = state[i][j] - 'A' + 'a';
                for (int k = 0; k < 5; k++) {
                    if (k == 4)return -1; //찾기 실패
                    intint new_p = { i + dxdy[k].fi,j + dxdy[k].se };
                    if (state[new_p.fi][new_p.se] == h) {
                        move_lines[h - 'a'] = (k + 2) % 4;
                        break;
                    }
                }

                queue<intint>arr;
                arr.push({ i,j });
                visit[i][j] = true;
                while (arr.size()) {
                    intint now_p = arr.front();
                    lines[h - 'a'].push_back(now_p);
                    arr.pop();
                    for (int k = 0; k < 4; k++) {
                        intint new_p = { now_p.fi + dxdy[k].fi, now_p.se + dxdy[k].se };
                        if (visit[new_p.fi][new_p.se] || h != state[new_p.fi][new_p.se])continue;
                        visit[new_p.fi][new_p.se] = true;
                        arr.push(new_p);
                    }
                }
            }
        }
    }

    while (t--) {
        for (int h = 0; h < 26; h++) {
            if (lines[h].size() <= 1)continue;
            char lower_h = 'a' + h;
            char upper_h = 'A' + h;
            
            intint now_p = lines[h].front();
            for (int k = 0; k < 3; k++) {
                int new_arrow = (move_lines[h] + give_dxdy[k] + 4) % 4;
                intint new_p = { now_p.fi + dxdy[new_arrow].fi,now_p.se + dxdy[new_arrow].se };
                if (state[new_p.fi][new_p.se] != '.')continue;
                state[new_p.fi][new_p.se] = upper_h;
                state[now_p.fi][now_p.se] = lower_h;
                state[lines[h].back().fi][lines[h].back().se] = '.';
                lines[h].pop_back();
                lines[h].push_front(new_p);
                move_lines[h] = new_arrow;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << state[i][j];
        }
        cout << "\n";
    }
}
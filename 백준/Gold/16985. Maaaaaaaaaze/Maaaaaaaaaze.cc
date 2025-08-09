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

int state[7][7][7];
int default_state[7][7][7];

int2_int dxdydz[6] = {
    {{-1,0},0},
    {{1,0},0},
    {{0,-1},0},
    {{0,1},0},
    {{0,0},-1},
    {{0,0},1}
};

void rotate_board(int deep) {
    int arr[7][7] = {};
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            arr[6-j][i] = state[deep][i][j];
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            state[deep][i][j] = arr[i][j];
        }
    }
}

int cal(int2_int start_p, int2_int end_p) {
    if (state[start_p.fi.fi][start_p.fi.se][start_p.se] == 0)return -1;
    if (state[end_p.fi.fi][end_p.fi.se][end_p.se] == 0)return -1;
    bool visit[7][7][7] = {};
    queue<int2_int>arr;
    visit[start_p.fi.fi][start_p.fi.se][start_p.se] = true;
    arr.push(start_p);
    for(int timer=1;arr.size();timer++){
        int size = arr.size();
        while (size--) {
            int2_int now_p = arr.front();
            arr.pop();
            for (int2_int xyz : dxdydz) {
                int2_int new_p = { {now_p.fi.fi + xyz.fi.fi,now_p.fi.se + xyz.fi.se},now_p.se + xyz.se };
                if (state[new_p.fi.fi][new_p.fi.se][new_p.se] == 0)continue;
                if (visit[new_p.fi.fi][new_p.fi.se][new_p.se])continue;
                visit[new_p.fi.fi][new_p.fi.se][new_p.se] = true;
                arr.push(new_p);
            }
        }
        if (visit[end_p.fi.fi][end_p.fi.se][end_p.se])return timer;
    }
    return -1;
}

void setting_state(vector<int>&arr) {
    for (int i = 1; i <= 5; i++) {
        for (int x = 1; x <= 5; x++) {
            for (int y = 1; y <= 5; y++) {
                state[i][x][y] = default_state[arr[i - 1]][x][y];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int deep = 1; deep <= 5; deep++) {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                cin >> default_state[deep][i][j];
            }
        }
    }

    vector<int>arr = { 1,2,3,4,5 };
    int ans = INF;
    
    do{
        setting_state(arr);
        for (int a = 1; a <= 4; a++) {
            for (int b = 1; b <= 4; b++) {
                for (int c = 1; c <= 4; c++) {
                    for (int d = 1; d <= 4; d++) {
                        for (int e = 1; e <= 4; e++) {
                            int h = cal({ {1,1},1 }, { {5,5 }, 5 });
                            if (h != -1)ans = min(ans, h);

                            rotate_board(5);
                        }
                        rotate_board(4);
                    }
                    rotate_board(3);
                }
                rotate_board(2);
            }
            rotate_board(1);
        }
    } while (next_permutation(arr.begin(), arr.end()));
    cout << (ans == INF ? -1 : ans);
}
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

int n;
int key_give = 1;

char state[52][52];
int key_state[52][52];
intint key_pos[253];

struct cmp {
    bool operator()(int2_int& a, int2_int& b) {
        return a.se > b.se;
    }
};
priority_queue<int2_int, vector<int2_int>, cmp>lines;

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int Union[253];
inline int Find(int n) {
    if (Union[n] == n)return n;
    return Union[n] = Find(Union[n]);
}

void append_line(int start_key) {
    bool visit[52][52] = {};
    queue<intint>arr;
    int timer = 1;
    intint start_p = key_pos[start_key];
    visit[start_p.fi][start_p.se] = true;
    arr.push(start_p);
    for (; arr.size(); timer++) {
        int size = arr.size();
        while (size--) {
            intint now_p = arr.front();
            arr.pop();
            for (intint xy : dxdy) {
                intint new_p = { now_p.fi + xy.fi,now_p.se + xy.se };
                if (visit[new_p.fi][new_p.se])continue;
                if (state[new_p.fi][new_p.se] == '1')continue;
                visit[new_p.fi][new_p.se] = true;
                if (state[new_p.fi][new_p.se] == 'K' || state[new_p.fi][new_p.se] == 'S') {
                    lines.push({ {start_key,key_state[new_p.fi][new_p.se]} ,timer });
                }
                arr.push(new_p);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin >> n >> w;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            state[i][j] = '1';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> state[i][j];
            if (state[i][j] == 'K') {
                key_pos[++key_give] = { i,j };
                key_state[i][j] = key_give;
            }
            if (state[i][j] == 'S') {
                key_pos[1] = { i,j };
                key_state[i][j] = 1;
            }
        }
    }
    for (int set_key = 1; set_key <= key_give; set_key++) {
        Union[set_key] = set_key;
        append_line(set_key);
    }

    int ans = 0;
    while (lines.size()) {
        bool is_one_here = false;
        int a = lines.top().fi.fi;
        int b = lines.top().fi.se;
        int cost = lines.top().se;
        lines.pop();
        a = Find(a);
        b = Find(b);
        if (a == b)continue;
        if (a > b)swap(a, b);
        Union[a] = b;
        ans += cost;
    }

    int key_const = Union[1];
    for (int i = 1; i <= key_give; i++) {
        if (Union[i] != key_const) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}

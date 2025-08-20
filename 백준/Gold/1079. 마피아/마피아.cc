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
int my_character;
int player_gulity[16];
int change_gulitiness[16][16];
bool player_out_state[16];
int ans = 0;
int night_survive = 0;
void dfs(int left_n) {
    if (left_n % 2 == 1) {
        int out_player = -1;
        int out_gulity = -nINF;
        for (int i = 0; i < n; i++) {
            if (player_out_state[i])continue;
            if (out_gulity < player_gulity[i]) {
                out_gulity = player_gulity[i];
                out_player = i;
            }
        }

        assert(out_player != -1);
        if (out_player == my_character) {
            ans = max(ans, night_survive);
            return;
        }
        player_out_state[out_player] = true;
        dfs(left_n - 1);
        player_out_state[out_player] = false;
        return;
    }

    night_survive++;
    for (int choose_out_player = 0; choose_out_player < n; choose_out_player++) {
        if (player_out_state[choose_out_player] || choose_out_player==my_character)continue;
        player_out_state[choose_out_player] = true;
        for (int i = 0; i < n; i++) {
            player_gulity[i] += change_gulitiness[choose_out_player][i];
        }
        dfs(left_n - 1); 
        for (int i = 0; i < n; i++) {
            player_gulity[i] -= change_gulitiness[choose_out_player][i];
        }
        player_out_state[choose_out_player] = false;
    }
    night_survive--;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> player_gulity[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> change_gulitiness[i][j];
        }
    }
    cin >> my_character;
    dfs(n);
    cout << ans;
}
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

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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

int ans = INF;
string maps[7];

intint dxdy[4] = { {-1,0},{0,-1},{1,0},{0,1} };

vector<intint>lines;

void dfs(vector<int>& number,int np) {
    ans = min(ans, int(number.size())-np);
    intint p = lines[number[np]];
    for (int i = 0; i < 4; i++) {
        int j = (i + 2) % 4;
        intint ixy = dxdy[i];
        intint jxy = dxdy[j];
        if (maps[p.fi + ixy.fi][p.se + ixy.se] == '.' && 0 <= maps[p.fi + jxy.fi][p.se + jxy.se] && maps[p.fi + jxy.fi][p.se + jxy.se] <= 7) {
            int h = maps[p.fi + jxy.fi][p.se + jxy.se];
            maps[p.fi + ixy.fi][p.se + ixy.se] = h;
            maps[p.fi + jxy.fi][p.se + jxy.se] = '.';
            int h2 = maps[p.fi][p.se];
            maps[p.fi][p.se] = '.';

            lines[h] = { p.fi + ixy.fi ,p.se + ixy.se };
            dfs(number, np + 1);
            lines[h] = { p.fi + jxy.fi ,p.se + jxy.se };

            maps[p.fi][p.se] = h2;
            maps[p.fi + ixy.fi][p.se + ixy.se] = '.';
            maps[p.fi + jxy.fi][p.se + jxy.se] = h;
        }
    }
}

void test() {
    vector<int>number;
    lines.clear();
    for (int i = 0; i < 7; i++) {
        maps[i] = "############";
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 'o') {
                maps[i][j] = number.size();
                number.push_back(number.size());
                lines.push_back({ i,j });
            }
        }
    }
    ans = INF;

    do {
        dfs(number, 0);
    } while (next_permutation(number.begin(), number.end()));

    assert(ans != INF);

    cout << ans << " " << number.size() - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
    }
}
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
typedef pair<int, char> int_char;

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
char state[52][52];
bool visit[52][52];

void debug_test(int n,int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << state[i][j];
        }
        cout << "\n";
    }
    cout << "====\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << visit[i][j];
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            visit[i][j] = true;
        }
    }
    int n, m;
    queue<intint>arr;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> state[i][j];
            visit[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (state[i][j] == 'X') {
                queue<intint>brr;
                brr.push({ i,j });
                state[i][j] = '.';
                while (brr.size()) {
                    intint p = brr.front();
                    brr.pop();
                    arr.push(p);
                    visit[p.fi][p.se] = true;
                    for (intint xy : dxdy) {
                        intint new_p = { p.fi + xy.fi,p.se + xy.se };
                        if (state[new_p.fi][new_p.se] != 'X')continue;
                        state[new_p.fi][new_p.se] = '.';
                        brr.push(new_p);
                    }
                }

                for (int loop = 0; arr.size(); loop++) {
                    int size = arr.size();
                    while (size--) {
                        intint p = arr.front();
                        arr.pop();
                        for (intint xy : dxdy) {
                            intint new_p = { p.fi + xy.fi,p.se + xy.se };
                            if (visit[new_p.fi][new_p.se])continue;
                            if (state[new_p.fi][new_p.se] == 'X') {
                                cout << loop;
                                return 0;
                            }
                            visit[new_p.fi][new_p.se] = true;
                            arr.push(new_p);
                        }
                    }
                }

                //debug_test(n, m);
                return -1;
            }
        }
    }
    return -1;
}
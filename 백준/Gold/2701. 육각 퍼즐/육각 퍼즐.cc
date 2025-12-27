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

pair<int,pair<char,vector<int>>> dp[7][7][7][7][7][7][7];

vector<int>lines[7];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, vector<int>>>arr;
    for (int a = 0; a < 7; a++) {
        for (int b = 0; b < 7; b++) {
            for (int c = 0; c < 7; c++) {
                for (int d = 0; d < 7; d++) {
                    for (int e = 0; e < 7; e++) {
                        for (int f = 0; f < 7; f++) {
                            for (int g = 0; g < 7; g++) {
                                dp[a][b][c][d][e][f][g] = { nINF,{'X',{}} };
                            }
                        }
                    }
                }
            }
        }
    }

    lines[0].push_back(1);
    lines[0].push_back(4);

    lines[1].push_back(0);
    lines[1].push_back(2);
    lines[1].push_back(6);

    lines[2].push_back(1);
    lines[2].push_back(3);

    lines[3].push_back(2);
    lines[3].push_back(4);

    lines[4].push_back(0);
    lines[4].push_back(3);
    lines[4].push_back(5);

    lines[5].push_back(4);
    lines[5].push_back(6);

    lines[6].push_back(5);
    lines[6].push_back(1);


    dp[0][5][6][1][2][3][4] = { 0,{'.',{}} };
    arr.push({ 0,vector<int>({ 0,5,6,1,2,3,4 }) });

    for (int timer = 1; !arr.empty(); timer++) {
        int size = arr.size();
        while (size--) {
            int now_zero_p = arr.front().fi;
            vector<int> state = arr.front().se;
            arr.pop();
            for (int new_zero_p : lines[now_zero_p]) {
                vector<int>new_state = state;
                swap(new_state[now_zero_p], new_state[new_zero_p]);
                if (dp[new_state[0]][new_state[1]][new_state[2]][new_state[3]][new_state[4]][new_state[5]][new_state[6]].se.fi != 'X')continue;
                dp[new_state[0]][new_state[1]][new_state[2]][new_state[3]][new_state[4]][new_state[5]][new_state[6]] = { timer,{'A' + state[new_zero_p] - 1,state} };
                arr.push({ new_zero_p,new_state });
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        string w;
        cin >> w;
        vector<int> state = { 0,w[4] - 'A' + 1,w[5] - 'A' + 1 ,w[0] - 'A' + 1 ,w[1] - 'A' + 1 ,w[2] - 'A' + 1 ,w[3] - 'A' + 1 };
        if (dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][state[6]].se.fi == 'X') {
            cout << "-1\n";
            continue;
        }
        cout << dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][state[6]].fi << " ";

        string ans = "";
        while (dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][state[6]].se.fi != '.') {
            ans += dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][state[6]].se.fi;
            state = dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][state[6]].se.se;
            //for (int h : dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][state[6]].se.se) {
            //    cout << h << ",";
            //}
            //cout << "로 변경.\n";
        }
        cout << ans << "\n";
    }
}
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

vector<vector<string>>windows;
set<vector<string>>diff;
char state[113][113];

void print_window(vector<string>arr) {
    cout << "출력 : \n";
    for (string h : arr) {
        cout << h << "\n";
    }
}
//주의점 : 창문이 정확히 직사각형 또는 정사각형이여야 한다.
void rotate_and_insert_window(int window_p) {
    diff.insert(windows[window_p]);
    //print_window(windows[window_p]);

    vector<string>arr;
    for (int i = int(windows[window_p].size()) - 1; i >= 0; i--) {
        string h = windows[window_p][i];
        reverse(h.begin(), h.end());
        arr.push_back(h);
    }

    diff.insert(arr);
    //print_window(arr);

    arr.clear();
    for (int j = int(windows[window_p][0].size()) - 1; j >= 0; j--) {
        string h = "";
        for (int i = 0; i < windows[window_p].size(); i++) {
            h.push_back(windows[window_p][i][j]);
        }
        arr.push_back(h);
    }

    diff.insert(arr);
    //print_window(arr);

    arr.clear();
    for (int j = 0; j < windows[window_p][0].size(); j++) {
        string h = "";
        for (int i = int(windows[window_p].size())-1; i >= 0; i--) {
            h.push_back(windows[window_p][i][j]);
        }
        arr.push_back(h);
    }

    diff.insert(arr);
    //print_window(arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 113; i++) {
        for (int j = 0; j < 113; j++) {
            state[i][j] = '#';
        }
    }

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> state[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (state[i - 1][j] == '#' && state[i][j - 1] == '#'
                && state[i][j] != '#') {
                vector<string>arr;
                for (int p_i = i; state[p_i][j] != '#'; p_i++) {
                    arr.push_back("");
                    for (int p_j = j; state[p_i][p_j] != '#'; p_j++) {
                        arr.back().push_back(state[p_i][p_j]);
                    }
                }
                windows.push_back(arr);
                //cout << "초기 ";
                //print_window(arr);
            }
        }
    }

    int ans = 0;
    for (int p = 0; p < windows.size(); p++) {
        if (diff.find(windows[p]) != diff.end())continue;
        ans++;
        rotate_and_insert_window(p);
    }

    cout << ans;
}
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

bool x_dp[102][102][102];
bool y_dp[102][102][102];

int2_int2 sort_line(intint a, intint b) {
    if (a.fi > b.fi || (a.fi == b.fi && a.se > b.se)) {
        swap(a, b);
    }
    return { a,b };
}

inline bool in_line(pair<dd,dd> a, dd b) {
    //cout << a.fi.fi << "~" << a.fi.se << " , " << a.se.fi << "~" << a.se.se << " / " << b.fi<<"," << b.se << "?\n";
    if ((a.fi.fi <= b.fi && b.fi <= a.se.fi) && (a.fi.se <= b.se && b.se <= a.se.se)) {
        //cout << "성공.\n";
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int2_int2>arr;
    vector<int>x_input;
    vector<int>y_input;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr.push_back(sort_line({ a, b }, { c,b }));
        arr.push_back(sort_line({ c, b }, { c,d }));
        arr.push_back(sort_line({ c, d }, { a,d }));
        arr.push_back(sort_line({ a, d }, { a,b }));

        x_input.push_back(a);
        x_input.push_back(c);
        y_input.push_back(b);
        y_input.push_back(d);
    }

    sort(x_input.begin(), x_input.end());
    sort(y_input.begin(), y_input.end());

    for (int i = 0; i < int(x_input.size()); i++) {
        for (int j = 0; j < int(y_input.size()) - 1; j++) {
            bool in_line_b = false;
            for (int2_int2& h : arr) {
                if (in_line(h, { x_input[i] + 0.0,y_input[j] + 0.5 })) {
                    in_line_b = true;
                    break;
                }
            }
            if (in_line_b) {
                y_dp[i][j][j + 1] = true;
            }
        }
    }

    for (int j = 0; j < int(y_input.size()); j++) {
        for (int i = 0; i < int(x_input.size()) - 1; i++) {
            bool in_line_b = false;
            for (int2_int2& h : arr) {
                if (in_line(h, { x_input[i] + 0.5,y_input[j] + 0.0 })) {
                    in_line_b = true;
                    break;
                }
            }
            if (in_line_b) {
                x_dp[j][i][i + 1] = true;
            }
        }
    }

    for (int len = 2; len < x_input.size(); len++) {
        for (int j = 0; j < y_input.size(); j++) {
            for (int i = 0; i + len < x_input.size(); i++) {
                x_dp[j][i][i + len] = (x_dp[j][i][i + len - 1] && x_dp[j][i + len - 1][i + len]);
            }
        }
    }

    for (int len = 2; len < y_input.size(); len++) {
        for (int i = 0; i < x_input.size(); i++) {
            for (int j = 0; j + len < y_input.size(); j++) {
                y_dp[i][j][j + len] = (y_dp[i][j][j + len - 1] && y_dp[i][j + len - 1][j + len]);
            }
        }
    }

    set<int2_int2>ans;
    for (int s_x = 0; s_x < x_input.size(); s_x++) {
        for (int s_y = 0; s_y < y_input.size(); s_y++) {
            for (int e_x = 0; e_x < x_input.size(); e_x++) {
                for (int e_y = 0; e_y < y_input.size(); e_y++) {
                    if (s_x >= e_x || s_y >= e_y || x_input[s_x] >= x_input[e_x] || y_input[s_y] >= y_input[e_y])continue;
                    if (abs(x_input[e_x] - x_input[s_x]) != abs(y_input[e_y] - y_input[s_y]))continue;
                    //cout << s_x << "," << s_y << " / " << e_x << "," << e_y << "시작.\n";
                    //cout << x_input[s_x] << "," << y_input[s_y] << "/" << x_input[e_x] << "," << y_input[e_y] << "임. \n";
                    //cout << "길이 : " << abs(x_input[e_x] - x_input[s_x]) << "\n";
                    //cout << " 상태 : " << x_dp[s_y][s_x][e_x] << "," << x_dp[e_y][s_x][e_x] << " | " << y_dp[s_x][s_y][e_y] << "," << y_dp[e_x][s_y][e_y] << "\n";
                    if (!x_dp[s_y][s_x][e_x])continue;
                    if (!x_dp[e_y][s_x][e_x])continue;
                    if (!y_dp[s_x][s_y][e_y])continue;
                    if (!y_dp[e_x][s_y][e_y])continue;

                    intint p1 = { x_input[s_x],y_input[s_y] };
                    intint p2 = { x_input[e_x],y_input[e_y] };
                    ans.insert({ p1,p2 });
                }
            }
        }
    }

    cout << ans.size();
}
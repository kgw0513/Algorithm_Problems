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

int arr_n, arr_m;
vector<vector<char>>arr;

int brr_n, brr_m;
vector<vector<char>>brr;

int ans = INF;

char crr[203][203];
intint start_p = { 52,52 };
void fill_crr() {
    for (int i = 0; i < 203; i++) {
        for (int j = 0; j < 203; j++) {
            crr[i][j] = 0;
        }
    }
    for (int a_i = 0; a_i < arr_n; a_i++) {
        for (int a_j = 0; a_j < arr_m; a_j++) {
            int i = a_i + start_p.fi;
            int j = a_j + start_p.se;
            crr[i][j] = arr[a_i][a_j];
        }
    }
}

void cal(intint p,int rotate) {
    fill_crr();
    
    if (rotate == 0) {
        for (int b_i = 0; b_i < brr_n; b_i++) {
            int c_i = p.fi + b_i;
            for (int b_j = 0; b_j < brr_m; b_j++) {
                int c_j = p.se + b_j;
                if (brr[b_i][b_j] == '1' && crr[c_i][c_j] == '1')return;
                crr[c_i][c_j] = '1';
            }
        }
    }
    if (rotate == 2) {
        for (int b_i = 0; b_i < brr_n; b_i++) {
            int c_i = p.fi + brr_n - b_i - 1;
            for (int b_j = 0; b_j < brr_m; b_j++) {
                int c_j = p.se + (brr_m - b_j - 1);
                if (brr[b_i][b_j] == '1' && crr[c_i][c_j] == '1')return;
                crr[c_i][c_j] = '1';
            }
        }
    }
    if (rotate == 1) {
        for (int b_i = 0; b_i < brr_n; b_i++) {
            int c_j = p.se + b_i;
            for (int b_j = 0; b_j < brr_m; b_j++) {
                int c_i = p.fi + brr_m - 1 - b_j;
                if (brr[b_i][b_j] == '1' && crr[c_i][c_j] == '1')return;
                crr[c_i][c_j] = '1';
            }
        }
    }
    if (rotate == 3) {
        for (int b_i = 0; b_i < brr_n; b_i++) {
            int c_j = p.se + brr_n - 1 - b_i;
            for (int b_j = 0; b_j < brr_m; b_j++) {
                int c_i = p.fi + b_j;
                if (brr[b_i][b_j] == '1' && crr[c_i][c_j] == '1')return;
                crr[c_i][c_j] = '1';
            }
        }
    }

    intint i_minmax = { INF,-INF };
    intint j_minmax = { INF,-INF };

    for (int i = 0; i < 203; i++) {
        for (int j = 0; j < 203; j++) {
            if (crr[i][j] != '1')continue;
            i_minmax.fi = min(i_minmax.fi, i);
            i_minmax.se = max(i_minmax.se, i);
            j_minmax.fi = min(j_minmax.fi, j);
            j_minmax.se = max(j_minmax.se, j);
        }
    }

    //cout << i_minmax.fi << "~" << i_minmax.se << " / " << j_minmax.fi << "~" << j_minmax.se << "\n";

    //cout << p.fi << "," << p.se <<"/" <<rotate<< ":" << (i_minmax.se - i_minmax.fi + 1) << "*" << (j_minmax.se - j_minmax.fi + 1) << "!!\n";
    ans = min(ans, (i_minmax.se - i_minmax.fi + 1) * (j_minmax.se - j_minmax.fi + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char w;
    cin >> arr_n >> arr_m;
    for (int i = 0; i < arr_n; i++) {
        arr.push_back(vector<char>());
        for (int j = 0; j < arr_m; j++) {
            cin >> w;
            arr[i].push_back(w);
        }
    }

    cin >> brr_n >> brr_m;
    for (int i = 0; i < brr_n; i++) {
        brr.push_back(vector<char>());
        for (int j = 0; j < brr_m; j++) {
            cin >> w;
            brr[i].push_back(w);
        }
    }

    for (int i = start_p.fi - brr_n; i <= start_p.fi + arr_n + brr_n; i++) {
        for (int j = start_p.se - brr_m; j <= start_p.se + arr_m + brr_m; j++) {
            for (int k = 0; k < 4; k++) {
                cal({ i,j },k);
            }
        }
    }

    cout << ans;
}
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

char crr[103][103];

int ans = INF;
void cal(intint p,int state) {
    for (int i = 0; i < 103; i++) {
        for (int j = 0; j < 103; j++) {
            crr[i][j] = '0';
        }
    }
    for (int i = 0; i < arr_n; i++) {
        for (int j = 0; j < arr_m; j++) {
            crr[i][j] = arr[i][j];
        }
    }

    if (state == 0) {
        for (int h_i = 0; h_i < brr_n; h_i++) {
            int a_i = h_i + p.fi;
            int b_i = h_i;
            for (int h_j = 0; h_j < brr_m; h_j++) {
                int a_j = h_j + p.se;
                int b_j = h_j;
                if (brr[b_i][b_j] == '0')continue;
                if (crr[a_i][a_j] != '1') {
                    crr[a_i][a_j] = '1';
                    continue;
                }
                return;
            }
        }
    }
    else if (state == 2) {
        for (int h_i = 0; h_i < brr_n; h_i++) {
            int a_i = h_i + p.fi;
            int b_i = brr_n - h_i - 1;
            for (int h_j = 0; h_j < brr_m; h_j++) {
                int a_j = h_j + p.se;
                int b_j = brr_m - h_j - 1;
                if (brr[b_i][b_j] == '0')continue;
                if (crr[a_i][a_j] != '1') {
                    crr[a_i][a_j] = '1';
                    continue;
                }
                return;
            }
        }
    }
    else if (state == 1) {
        for (int h_i = 0; h_i < brr_m; h_i++) {
            int a_i = h_i + p.fi;
            int b_j = brr_m - h_i - 1;
            for (int h_j = 0; h_j < brr_n; h_j++) {
                int a_j = h_j + p.se;
                int b_i = h_j;
                if (brr[b_i][b_j] == '0')continue;
                if (crr[a_i][a_j] != '1') {
                    crr[a_i][a_j] = '1';
                    continue;
                }
                return;
            }
        }
    }
    else if (state == 3) {
        for (int h_i = 0; h_i < brr_m; h_i++) {
            int a_i = h_i + p.fi;
            int b_j = h_i;
            for (int h_j = 0; h_j < brr_n; h_j++) {
                int a_j = h_j + p.se;
                int b_i = brr_n - h_j - 1;
                if (brr[b_i][b_j] == '0')continue;
                if (crr[a_i][a_j] != '1') {
                    crr[a_i][a_j] = '1';
                    continue;
                }
                return;
            }
        }
    }

    intint i_minmax = { INF,-INF };
    intint j_minmax = { INF,-INF };

    for (int i = 0; i < 103; i++) {
        for (int j = 0; j < 103; j++) {
            if (crr[i][j] == '1') {
                i_minmax.fi = min(i_minmax.fi, i);
                i_minmax.se = max(i_minmax.se, i);
                j_minmax.fi = min(j_minmax.fi, j);
                j_minmax.se = max(j_minmax.se, j);
            }
        }
    }

    //cout << p.fi << "," << p.se << "/" << state << "상태 성공. => "<< (i_minmax.se - i_minmax.fi + 1)<<"*"<< (j_minmax.se - j_minmax.fi + 1)<<"\n";
    //cout << "현 결과 : " << ans << " => ";
    ans = min(ans, (i_minmax.se - i_minmax.fi + 1) * (j_minmax.se - j_minmax.fi + 1));
    //cout << ans << "\n";
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

    for (int i = 0; i <= arr_n; i++) {
        for (int j = 0; j <= arr_m; j++) {
            for (int k = 0; k < 4; k++) {
                cal({ i,j }, k);
            }
        }
    }

    swap(arr_n, brr_n);
    swap(arr_m, brr_m);
    swap(arr, brr);

    for (int i = 0; i <= arr_n; i++) {
        for (int j = 0; j <= arr_m; j++) {
            for (int k = 0; k < 4; k++) {
                cal({ i,j }, k);
            }
        }
    }

    assert(ans != INF);
    cout << ans;
}
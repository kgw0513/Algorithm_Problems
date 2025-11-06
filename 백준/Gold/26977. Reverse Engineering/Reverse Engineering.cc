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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<string, int>>arr(m);
        vector<bool>used(m, false);
        vector<vector<bool>>brr(m, vector<bool>(n, false));
        for (pair<string, int>& w : arr) {
            cin >> w.fi >> w.se;
        }

        for (int test = 1; test <= 2 * n; test++) {
            //cout << test << "중.\n";
            bool change_once = false;
            for (int cn = 0; cn < n && !change_once; cn++) {
                for (int num_state = 0; num_state <= 1 && !change_once; num_state++) {
                    bool is_can = true;
                    int first_change = -1;
                    for (int i = 0; i < m; i++) {
                        //cout << i << "번째에서 " << cn << "/" << num_state << "돌리는 중.\n";
                        if (used[i])continue;
                        if ((arr[i].fi[cn] - '0') != num_state)continue;
                        if (first_change == -1 || first_change == arr[i].se) {
                            first_change = arr[i].se;
                            continue;
                        }
                        //cout << cn << "/" << num_state << "에서 " << first_change << "랑 다름.\n";
                        is_can = false;
                        break;
                    }
                    //cout << first_change << "," << is_can << "이라는 결과 나옴.\n";
                    if (first_change == -1 || !is_can)continue;
                    change_once = true;
                    //cout << "들.\n";
                    for (int i = 0; i < m; i++) {
                        if (used[i])continue;
                        if ((arr[i].fi[cn] - '0') != num_state)continue;
                        used[i] = true;
                    }
                }
            }

            if (!change_once)break;
        }

        bool is_can = true;
        for (int i = 0; i < m; i++) {
            if (used[i])continue;
            //cout << i << "는 false" << "\n";
            is_can = false;
            break;
        }

        cout << (is_can ? "OK" : "LIE") << "\n";
    }
}
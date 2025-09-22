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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    while (cin >> n) {
        cin >> m;
        vector<int>arr(n+1);
        int max_ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            max_ans = max(max_ans, arr[i]);
        }

        vector<vector<int>>lines(n + 1);
        vector<bitset<460>>state(n + 1);

        queue<pair<bitset<460>,int>>brr;
        while (m--) {
            cin >> a >> b;
            lines[a].push_back(b);
            lines[b].push_back(a);
            state[a][b] = 1;
            state[b][a] = 1;

            bitset<460>setting;
            setting[a] = 1;
            setting[b] = 1;
            brr.push({ setting ,arr[a]+arr[b]});
        }

        for (int i = 1; i <= n; i++) {
            state[i][i] = 1;
        }

        while (brr.size()) {
            bitset<460>now_state = brr.front().fi;
            int now_sum = brr.front().se;
            brr.pop();
            max_ans = max(max_ans, now_sum);
            for (int i = 1; i <= n; i++) {
                if (now_state[i] == 1)continue;
                if ((now_state & state[i]) != now_state)continue;
                bitset<460>new_state = now_state;
                int new_sum = now_sum + arr[i];
                new_state[i] = 1;
                brr.push({ new_state,new_sum });
            }
        }
        cout << max_ans << "\n";
    }
}
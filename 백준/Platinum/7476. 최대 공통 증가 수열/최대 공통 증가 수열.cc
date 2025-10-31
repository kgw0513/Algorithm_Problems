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

unordered_map<int, int>val2num;
unordered_map<int, int>num2val;

short dp[505][505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    deque<int>arr(n);
    set<int>sort_set;
    for (int& w : arr) {
        cin >> w;
        sort_set.insert(w);
    }
    cin >> m;
    int counting = 0;
    for (int val : sort_set) {
        val2num.insert({ val,++counting });
        //cout << val << "<=>" << counting << "??\n";
        num2val.insert({ counting,val });
    }
    for (int& w : arr) {
        //cout << w << "->" << val2num[w] << "\n";
        w = val2num[w];
    }
    deque<int>brr;
    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        if (sort_set.find(w) == sort_set.end())continue;
        brr.push_back(val2num[w]);
    }
    m = brr.size();

    arr.push_front(-1);
    brr.push_front(-1);

    //cout << "arr:\n";
    //for (int& w : arr) {
    //    cout << w << ",";
    //}
    //cout << "\n brr : \n";
    //for (int& w : brr) {
    //    cout << w << ",";
    //}
    //cout << "\n";

    for (int k = 1; k <= counting; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i] == k && brr[j] == k) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k],dp[i][j][k - 1] });
                }
            }
        }
    }
    stack<int>ans;

    int2_int p = { {n,m},counting };
    while (p.fi.fi > 0 && p.fi.se > 0 && p.se > 0) {
        if (dp[p.fi.fi][p.fi.se][p.se] == dp[p.fi.fi - 1][p.fi.se][p.se]) {
            p.fi.fi--;
            continue;
        }
        if (dp[p.fi.fi][p.fi.se][p.se] == dp[p.fi.fi][p.fi.se - 1][p.se]) {
            p.fi.se--;
            continue;
        }
        if (dp[p.fi.fi][p.fi.se][p.se] == dp[p.fi.fi][p.fi.se][p.se - 1]) {
            p.se--;
            continue;
        }
        ans.push(num2val[arr[p.fi.fi]]);
        p.fi.fi--;
        p.fi.se--;
        p.se--;
    }
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
        if (!ans.empty())cout << " ";
    }
}
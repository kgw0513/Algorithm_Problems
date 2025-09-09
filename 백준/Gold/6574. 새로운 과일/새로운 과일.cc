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

string cal(string a,string b) {
    a = '0' + a;
    b = '0' + b;
    vector<vector<int>>arr(a.size()+1,vector<int>(b.size()+1,nINF));
    arr[0][0] = 0;
    for (int i = 0; i < a.size(); i++) {
        arr[i][0] = i;
    }
    for (int i = 0; i < b.size(); i++) {
        arr[0][i] = i;
    }
    for (int a_i = 1; a_i < a.size(); a_i++) {
        for (int b_i = 1; b_i < b.size(); b_i++) {
            arr[a_i][b_i] = min(arr[a_i][b_i - 1], arr[a_i - 1][b_i]) + 1;
            if (a[a_i] == b[b_i]) {
                arr[a_i][b_i] = min(arr[a_i][b_i], arr[a_i - 1][b_i - 1]);
            }
        }
    }
    //for (int a_i = 0; a_i < a.size(); a_i++) {
    //    for (int b_i = 0; b_i < b.size(); b_i++) {
    //        cout << arr[a_i][b_i] << ",";
    //    }
    //    cout << "\n";
    //}
    //cout << "중.\n";

    string ans = "";
    intint p = { a.size() - 1,b.size() - 1 };
    while (p.fi>0 && p.se>0) {
        //cout << p.fi << ',' << p.se << "이동.\n";
        if (a[p.fi] == b[p.se] && arr[p.fi - 1][p.se - 1] == arr[p.fi][p.se]) {
            ans += a[p.fi];
            p.fi--;
            p.se--;
            continue;
        }
        if (arr[p.fi - 1][p.se] + 1 == arr[p.fi][p.se]) {
            ans += a[p.fi];
            p.fi--;
        }
        else {
            ans += b[p.se];
            p.se--;
        }
    }
    while (p.fi > 0) {
        ans += a[p.fi];
        p.fi--;
    }
    while (p.se > 0) {
        ans += b[p.se];
        p.se--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    while (cin >> a) {
        cin >> b;
        cout << cal(a, b) << "\n";
    }
}
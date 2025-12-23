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
 
vector<int>lines[2];
 
int question(string saying) {
    int w = 0;
    cout << "? " << saying << "\n" << flush;
    cin >> w;
    return w;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans.push_back('0');
        lines[0].push_back(i);
    }
    random_shuffle(lines[0].begin(), lines[0].end());
 
    int default_count = question(ans);
 
    for (int i = 0; i + 2 <= lines[0].size(); i += 2) {
        ans[lines[0][i]] = '1';
        ans[lines[0][i + 1]] = '1';
        int h = question(ans);
        if (default_count - h == 2) {
            ans[lines[0][i]] = '0';
            ans[lines[0][i + 1]] = '0';
            default_count = max(default_count, h);
            continue;
        }
        else if (h - default_count == 2) {
            default_count = max(default_count, h);
            continue;
        }
 
        ans[lines[0][i]] = '0';
        ans[lines[0][i + 1]] = '0';
        lines[1].push_back(lines[0][i]);
        lines[1].push_back(lines[0][i + 1]);
    }
 
    if (lines[0].size() % 2 == 1) {
        ans[lines[0].back()] = '1';
        int h = question(ans);
        if (h < default_count) {
            ans[lines[0].back()] = '0';
        }
        else {
            default_count++;
        }
    }
 
    for (int i = 0; i + 4 <= lines[1].size(); i += 4) {
        ans[lines[1][i]] = '0';
        ans[lines[1][i + 1]] = '1';
        ans[lines[1][i + 2]] = '0';
        ans[lines[1][i + 3]] = '1';
        int h = question(ans);
        if (default_count - h == 2) {
            ans[lines[1][i]] = '1';
            ans[lines[1][i + 1]] = '0';
            ans[lines[1][i + 2]] = '1';
            ans[lines[1][i + 3]] = '0';
            default_count+=2;
            continue;
        }
        else if (h - default_count == 2) {
            default_count = max(default_count, h);
            continue;
        }
 
        ans[lines[1][i]] = '0';
        ans[lines[1][i + 1]] = '1';
        ans[lines[1][i + 2]] = '1';
        ans[lines[1][i + 3]] = '0';
        h = question(ans);
        assert(abs(default_count - h) == 2);
        if (default_count - h > 0) {
            ans[lines[1][i]] = '1';
            ans[lines[1][i + 1]] = '0';
            ans[lines[1][i + 2]] = '0';
            ans[lines[1][i + 3]] = '1';
            default_count+=2;
            continue;
        }
        else if (default_count - h < 0) {
            default_count = max(default_count, h);
            continue;
        }
    }
 
    if (lines[1].size() % 4 == 2) {
        int back_p = lines[1].size() - 1;
        ans[lines[1][back_p - 1]] = '0';
        ans[lines[1][back_p]] = '1';
        int h = question(ans);
        if (h != ans.size()) {
            ans[lines[1][back_p - 1]] = '1';
            ans[lines[1][back_p]] = '0';
        }
    }
 
    cout << "! " << ans << flush;
}

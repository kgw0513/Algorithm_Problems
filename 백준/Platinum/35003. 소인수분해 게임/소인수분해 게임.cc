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
 
bool check[1000000] = { 1,1 };
vector<ll>sosu;
 
map<pair<vector<ll>, pair<ll,bool>>,bool>ans;
 
bool dfs(vector<ll>state, ll last_out,bool y_turn) {
    if (ans.find({ state,{last_out,y_turn} }) != ans.end()) {
        return ans[{state, { last_out,y_turn }}];
    }
 
    for (int i = 0; i < state.size(); i++) {
        if (state[i] <= 0 || i==last_out)continue;
        vector<ll>state2 = state;
        state2[i]--;
        ll now_out = i;
        for (int j = i; j >= 1; j--) {
            if (state2[j] < state2[j - 1]) {
                swap(state2[j], state2[j - 1]);
                now_out = j - 1;
                continue;
            }
            break;
        }
        if (y_turn == dfs(state2, now_out, !y_turn)) {
            return ans[{state, { last_out,y_turn }}] = y_turn;
        }
    }
    return ans[{state, { last_out,y_turn }}] = !y_turn;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 2; i < 1000000; i++) {
        if (check[i])continue;
        sosu.push_back(i);
        for (ll j = i * i; j < 1000000; j += i) {
            check[j] = true;
        }
    }
 
    ll t, w;
    cin >> t;
    while (t--) {
        cin >> w;
        vector<ll>state;
        for (ll& h : sosu) {
            ll sum = 0;
            while (w % h == 0) {
                w /= h;
                sum++;
            }
            if (sum > 0)state.push_back(sum);
        }
        if (w != 1)state.push_back(1);
        while (state.size() < 11) {
            state.push_back(0);
        }
        sort(state.begin(), state.end());
        if (dfs(state, -1, true))cout << "yyyy7089\n";
        else cout << "toycartoon\n";
    }
}

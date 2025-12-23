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
 
string cartoon = "toycartoon";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string w;
    cin >> w;
 
    intint max_o_state = { 0,-1 }; //{위치,길이}
    for (int s = 0; s < cartoon.size(); s++) {
        int i = 0;
        for (; i < w.size() && s + i < cartoon.size() && w[i] == cartoon[s + i]; i++);
 
        if (max_o_state.se < i)max_o_state = { s,i };
    }
 
    if (max_o_state.se == 0) {
        //나중에 여기 조건 처리 안하면 틀리는지 확인.
        string ans = cartoon + "_" + w;
        if (ans.size() <= 20)cout << ans;
        else cout << cartoon;
        return 0;
    }
 
    string left_w = w.substr(max_o_state.se);
    int check_s = max_o_state.fi + max_o_state.se;
    int match_len = 0;
 
    for (int len = 0; len < left_w.size() && check_s + len < cartoon.size(); len++) {
        bool all_match = true;
        for (int i = 0; i <= len; i++) {
            if (left_w[int(left_w.size()) - 1 - (len - i)] != cartoon[check_s + i]) {
                all_match = false;
                break;
            }
        }
        if (!all_match)continue;
        match_len = max(match_len, len + 1);
    }
    string ans = (max_o_state.fi > 0 ? cartoon.substr(0, max_o_state.fi) : "");
    ans += w;
    int y_s = check_s + match_len;
    int y_len = int(cartoon.size()) - y_s;
    ans += (y_len > 0 ? cartoon.substr(y_s, y_len) : "");
 
    if (ans.size() <= 20)cout << ans;
    else cout << cartoon;
}

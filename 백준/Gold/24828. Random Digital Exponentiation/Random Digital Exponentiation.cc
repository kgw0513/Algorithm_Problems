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

stack<int>ans;
string a;
ll b;

bool setting(int p,ll state) {
    if (state > b)return false;

    if (p >= a.size()) {
        if (state == b) {
            return true;
        }
        return false;
    }

    //근데 어차피 고유하다 해서 0,1은 안들어올듯
    if (a[p] == '0') {
        if (setting(p + 1, state * 10)) {
            ans.push(0);
            return true;
        }
        return false;
    }
    else if (a[p] == '1') {
        if (setting(p + 1, state * 10)) {
            ans.push(0);
            return true;
        }
        if (setting(p + 1, state * 10 + (a[p] - '0'))) {
            ans.push(1);
            return true;
        }
        return false;
    }
    else {
        ll h = 1;
        ll max_len = 0;
        while (h * (a[p] - '0') <= b - state*pow(10,a.size()-p)) {
            max_len++;
            h *= (a[p] - '0');
        }
        for (int i = max_len; i >= 0; i--) {
            if (setting(p + 1, state * 10 + h)) {
                ans.push(i);
                return true;
            }
            h /= (a[p] - '0');
        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;

    if (setting(0, 0)) {
        while (ans.size()) {
            int h = ans.top();
            ans.pop();
            cout << h;
            if (!ans.empty())cout << " ";
        }
        return 0;
    }

    cout << "None";
}
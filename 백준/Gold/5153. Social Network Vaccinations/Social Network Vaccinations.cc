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

void setting(vector<int>& arr, const string& w) {
    bool not_in = true;
    int number = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == ' ') {
            if (!not_in)arr.push_back(number);
            number = 0;
            not_in = true;
            continue;
        }
        number = number * 10 + (w[i] - '0');
        not_in = false;
    }
    if (!not_in)arr.push_back(number);
}

vector<int>lines[31];
int Union[31];
int Union_Counting[31];
int Find(int n) {
    if (n == Union[n])return n;
    return Union[n] = Find(Union[n]);
}

int ans;
int n, d;

bool blocking[31];
void cal(int p, int counting) {
    if (counting >= d) {
        for (int loop = 1; loop <= n; loop++) {
            Union[loop] = loop;
            Union_Counting[loop] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (blocking[i])continue;
            for (int j : lines[i]) {
                if (blocking[j])continue;
                int ii = Find(i);
                int jj = Find(j);
                if (ii == jj)continue;

                if (ii > jj)swap(ii, jj);
                Union_Counting[jj] += Union_Counting[ii];
                Union[ii] = jj;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = max(sum, Union_Counting[i]);
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = p; i <= n; i++) {
        blocking[i] = true;
        cal(i + 1, counting + 1);
        blocking[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string w;
    {
        vector<int>helper_vec;
        getline(cin, w);
        setting(helper_vec, w);
        t = helper_vec[0];
    }
    for(int test=1;test<=t;test++){
        if (test >= 2)cout << "\n";
        vector<int>helper_vec;
        getline(cin, w);
        setting(helper_vec, w);
        n = helper_vec[0];
        d = helper_vec[1];
        for (int loop = 1; loop <= n; loop++) {
            getline(cin, w);
            lines[loop].clear();
            setting(lines[loop], w);
        }
        ans = n;
        cal(1, 0);
        cout << "Data Set " << test << ":\n";
        cout << ans << "\n";
    }
}

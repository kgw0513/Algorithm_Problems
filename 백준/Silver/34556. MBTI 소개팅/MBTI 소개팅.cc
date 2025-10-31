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

bool visit[1 << 10][1 << 10];
int ans[1 << 10][1 << 10];
vector<string>man;
vector<string>woman;

int comp(string a, string b) {
    int diff = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])diff++;
    }
    return diff;
}
int dfs(int man_match, int woman_match, const int n) {
    if (visit[man_match][woman_match])return ans[man_match][woman_match];
    visit[man_match][woman_match] = true;
    for (int i = 0; i < n; i++) {
        int now_man = (1 << i);
        if ((man_match & now_man) != 0)continue;
        for (int j = 0; j < n; j++) {
            int now_woman = (1 << j);
            if ((woman_match & now_woman) != 0)continue;
            ans[man_match][woman_match] = max(ans[man_match][woman_match], dfs(man_match | now_man, woman_match | now_woman, n) + comp(man[i], woman[j]));
        }
    }
    return ans[man_match][woman_match];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        man.push_back(w);
    }
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        woman.push_back(w);
    }

    cout << dfs(0, 0, n);
}
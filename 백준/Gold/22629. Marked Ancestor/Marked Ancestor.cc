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

vector<int>lines[100002];
ll ans = 0;

vector<int>state[100002];

bool cmp(const intint& a, const intint& b)
{
    return a.fi < b.fi;
}

//{쿼리 입력 순 , 정점}
void dfs(int now_p, int last_p, vector<intint> &cur) {
    stack<intint>brr;
    //cout << now_p << "들옴,.\n";
    for (int& h : state[now_p]) {
        //cout << now_p << "에서 " << h << "상태.\n";
        if (h > 0) {
            int h2 = upper_bound(cur.begin(), cur.end(), intint({ h,0 }), cmp) - cur.begin();
            h2--;
            ans += cur[h2].se;
        }
        else {
            int h2 = -h;
            while (cur.size() && cur.back().fi >= h2) {
                brr.push(cur.back());
                cur.pop_back();
            }
            cur.push_back({ h2,now_p });
            brr.push({ -1,-1 });
        }
    }

    for (int& next_p : lines[now_p]) {
        if (next_p == last_p)continue;
        //cout << now_p << "->" << next_p << "감.\n";
        dfs(next_p, now_p, cur);
    }

    while (brr.size()) {
        if (brr.top().fi == -1)cur.pop_back();
        else cur.push_back(brr.top());
        brr.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char a;
    int w;
    for (int i = 2; i <= n; i++) {
        cin >> w;
        lines[w].push_back(i);
        lines[i].push_back(w);
        //cout << w << "<->" << i << "\n";
    }

    //cout << lines[1].size() << "개.\n";
    for (int timer = 1; timer <= m; timer++) {
        cin >> a >> w;
        if (a == 'Q') {
            state[w].push_back(timer);
        }
        else state[w].push_back(-timer);
    }

    vector<intint>first_state = { {0,1 } };
    dfs(1, -1, first_state);

    cout << ans;
}
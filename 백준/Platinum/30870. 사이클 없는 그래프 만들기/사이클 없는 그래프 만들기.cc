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

int n, m;
vector<int>lines[200002];
bool visit[200002];
vector<intint>pairline;

int Union[200002];
int Find(int n) {
    if (n == Union[n])return n;
    return Union[n] = Find(Union[n]);
}

bool cal(queue<int>arr,int set_time) {
    fill(visit, visit + 200002, false);

    for (int i = 0; i < 200002; i++) {
        Union[i] = i;
    }

    {
        int size = arr.size();
        while (size--) {
            int now_p = arr.front();
            arr.pop();
            visit[now_p] = true;
            arr.push(now_p);
        }
    }

    for (int timer = 2; timer <= set_time && arr.size(); timer++) {
        int size = arr.size();
        while (size--) {
            int now_p = arr.front();
            arr.pop();
            for (int next_p : lines[now_p]) {
                if (visit[next_p])continue;
                visit[next_p] = true;
                arr.push(next_p);
            }
        }
    }

    for (intint h : pairline) {
        if (visit[h.fi] || visit[h.se])continue;
        h.fi = Find(h.fi);
        h.se = Find(h.se);
        if (h.fi == h.se)return true;
        if (h.fi > h.se)swap(h.fi, h.se);
        Union[h.fi] = h.se;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, a, b;
    cin >> n >> m >> k;
    queue<int>remove_point;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        lines[a].push_back(b);
        lines[b].push_back(a);
        pairline.push_back({ a,b });
    }
    while (k--) {
        cin >> a;
        remove_point.push(a);
    }

    int s = 1, e = n;
    int ans = e;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (cal(remove_point,mid)) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
}
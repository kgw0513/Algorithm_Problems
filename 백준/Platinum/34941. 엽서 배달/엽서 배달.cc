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
#include <complex>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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

//unordered_set, unordered_map 전용 (구조체로 쓸 경우 == operator도 필요)
//사용 예시 : unordered_set<intint,pair_hash> arr;
namespace std {
    struct default_hash {
        template <class T1>
        size_t operator()(const T1 n) const {
            hash<T1> a{}; size_t sa = a(n);
            return sa;
        }
    };
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> n) const {
            hash<T1> a{}; size_t sa = a(n.fi);
            hash<T2> b{}; size_t sb = b(n.se);
            return sa ^ sb;
        }
    };
}

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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

ll n;
unordered_map<intint, ll, pair_hash>costs;
vector<int>lines[300002];

struct Node {
    ll all_in_cost; //간 정점에 들어가는 모든 비용
    ll all_sum; //총 합
    int all_count; //총 갯수
};

Node dfs(int p, int lp) {

    vector<pair<int,Node>>arr;
    for (int i = 0; i < lines[p].size(); i++) {
        int np = lines[p][i];
        if (np == lp)continue;
        arr.push_back({ np, dfs(np, p) });
    }

    //그동안 갈 수 있던 정점에 들은 정점 갯수 합 (본인꺼 포함)
    ll all_count = 1;
    for (pair<int, Node>& h : arr)all_count += h.se.all_count;

    ll all_in_costs = 0;
    Node ans;
    //현재 정점에 우체국이 있다 가정할때
    {
        for (int i = 0; i < arr.size(); i++) {
            //들어가는 비용 계산 : 해당 정점안의 들어가는 모든 비용 + 현재 가는 비용*안의 갯수
            all_in_costs += arr[i].se.all_in_cost + costs[{p, arr[i].fi}] * arr[i].se.all_count;
        }

        ans.all_count = all_count;
        ans.all_in_cost = all_in_costs;
        ans.all_sum = all_in_costs;
    }

    //내가 간 정점쪽에 우체국이 있다 가정할때
    for (int i = 0; i < arr.size(); i++) {
        ll mail_start_cost = costs[{arr[i].fi,p}] * (n - arr[i].se.all_count);
        ll now_sum = arr[i].se.all_sum + (all_in_costs - (arr[i].se.all_in_cost + costs[{p, arr[i].fi}] * arr[i].se.all_count));
        now_sum += mail_start_cost;

        if (ans.all_sum > now_sum) {
            ans.all_count = all_count;
            ans.all_in_cost = all_in_costs;
            ans.all_sum = now_sum;
        }
    }

    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c, d;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b >> c >> d;
        lines[a].push_back(b);
        lines[b].push_back(a);
        costs[{a, b}] = c;
        costs[{b, a}] = d;
    }

    Node h = dfs(1, -1);
    cout << h.all_sum;
}
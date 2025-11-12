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
#include <cassert>
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

//사람 : 1~n , 서점 : n+1,n+m
// s:n+m+1,e:n+m+2

int Flow[212][212];
int Cap[212][212];

int Cost[212][212];

int State[212];
int BackTrack[212];
bool InQueue[212];

vector<int>lines[212];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, w;
    cin >> n >> m;

    int s = n + m + 1;
    int e = s + 1;

    for (int i = 1; i <= n; i++) {
        cin >> w;
        lines[s].push_back(i);
        lines[i].push_back(s);
        Cap[s][i] = w;
    }

    for (int i = 1; i <= m; i++) {
        cin >> w;
        lines[n+i].push_back(e);
        lines[e].push_back(n+i);
        Cap[n+i][e] = w;
    }

    for (int store = n + 1; store <= n + m; store++) {
        for (int people = 1; people <= n; people++) {
            cin >> w;
            lines[people].push_back(store);
            lines[store].push_back(people);
            Cost[people][store] = w;
            Cost[store][people] = -w;
            Cap[people][store] = nINF;
        }
    }

    int ans = 0;
    while (1) {
        for (int i = 1; i <= n + m+2; i++) {
            State[i] = nINF;
            BackTrack[i] = -1;
        }
        State[s] = 0;

        queue<int>arr;
        arr.push(s);
        while (arr.size()) {
            int now_p = arr.front();
            arr.pop();
            InQueue[now_p] = false;
            for (int& next_p : lines[now_p]) {
                if (Cap[now_p][next_p] - Flow[now_p][next_p] <= 0)continue;
                if (State[next_p] <= State[now_p] + Cost[now_p][next_p])continue;
                State[next_p] = State[now_p] + Cost[now_p][next_p];
                BackTrack[next_p] = now_p;

                if (InQueue[next_p])continue;
                arr.push(next_p);
                InQueue[next_p] = true;
            }
        }

        if (BackTrack[e] == -1)break;

        int now_flow = nINF;
        int p = e;
        while (BackTrack[p] != -1) {
            now_flow = min(now_flow, Cap[BackTrack[p]][p] - Flow[BackTrack[p]][p]);
            p = BackTrack[p];
        }

        assert(p == s);

        //cout << now_flow << " : ";
        p = e;
        while (BackTrack[p] != -1) {
            //cout << p << "("<< Cost[BackTrack[p]][p]<<")->";
            ans += now_flow * Cost[BackTrack[p]][p];
            Flow[BackTrack[p]][p] += now_flow; 
            Flow[p][BackTrack[p]] -= now_flow;
            p = BackTrack[p];
        }
        //cout << "\n";
    }

    cout << ans;
}
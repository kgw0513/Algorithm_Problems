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

int student_number;
intint student[250005];
vector<int>lines[250005];
int state[505][505];

int visit[505][505];
intint dxdy[8] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1} };

int Union[250005];
void bfs(int start_p){
    queue<int2_int>arr;
    set<int>brr;
    set<int>crr;
    crr.insert(start_p);
    arr.push({ student[start_p],start_p });
    visit[student[start_p].fi][student[start_p].se] = -1;

    while (arr.size()) {
        brr.clear();
        while (arr.size()) {
            intint p = arr.front().fi;
            int num = arr.front().se;
            arr.pop();
            
            for (intint xy : dxdy) {
                intint new_p = { p.fi + xy.fi,p.se + xy.se };
                if (state[new_p.fi][new_p.se] == 0 || visit[new_p.fi][new_p.se] < 0)continue;
                if (visit[new_p.fi][new_p.se] != 0 && visit[new_p.fi][new_p.se] <= num)continue;
                visit[new_p.fi][new_p.se] = num;
                brr.insert(state[new_p.fi][new_p.se]);
                crr.insert(state[new_p.fi][new_p.se]);
            }
        }

        for (int h : brr) {
            assert(visit[student[h].fi][student[h].se] > 0);
            lines[h].push_back(visit[student[h].fi][student[h].se]);
            Union[visit[student[h].fi][student[h].se]]++;
            arr.push({ student[h], h });
            visit[student[h].fi][student[h].se] *= -1;
        }
    }

    if (crr.size() != student_number) {
        cout << -1;
        exit(0);
    }
}

int ans[250005];
bool student_visit[250005];

void cal() {
    queue<int>arr;
    for (int i = 1; i <= student_number; i++) {
        if (Union[i] != 0)continue;
        arr.push(i);
        ans[i] = 1;
    }
    while (arr.size()) {
        int p = arr.front();
        arr.pop();
        for (int next_p : lines[p]) {
            Union[next_p]--;
            ans[next_p] += ans[p];
            if (Union[next_p] != 0)continue;
            ans[next_p]++;
            arr.push(next_p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, s;
    cin >> n >> m >> student_number;
    for (int i = 1; i <= student_number; i++) {
        cin >> a >> b;
        state[a][b] = i;
        student[i] = { a,b };
    }
    cin >> s;
    bfs(s);
    cal();
    cout << ans[1];
    for (int i = 2; i <= student_number; i++) {
        cout << " " << ans[i];
    }
}
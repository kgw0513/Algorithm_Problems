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
 
char state[752][752];
int visit_cost[752][752];
intint track_state[752][752];
 
//{좌표,비용}
struct cmp {
    bool operator()(int2_int& a, int2_int& b) {
        return a.se > b.se;
    }
};
 
intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
 
void reset_state() {
    for (int i = 0; i < 752; i++) {
        for (int j = 0; j < 752; j++) {
            track_state[i][j] = {};
            visit_cost[i][j] = nINF;
        }
    }
}
pair<int, vector<intint>> cal(intint s, intint e, int dot_num) {
    reset_state();
 
    vector<intint> track;
    int ans = 0;
 
    priority_queue<int2_int, vector<int2_int>, cmp>arr;
    arr.push({ s,dot_num });
    visit_cost[s.fi][s.se] = dot_num;
    track_state[s.fi][s.se] = { -1,-1 };
 
    while (arr.size()) {
        intint now_p = arr.top().fi;
        int now_cost = arr.top().se;
        arr.pop();
        //방문가격과 다를경우 이미 더 작은 비용이 존재한다는거니 무시하기
        if (visit_cost[now_p.fi][now_p.se] != now_cost)continue;
 
        for (intint xy : dxdy) {
            intint new_p = { now_p.fi + xy.fi,now_p.se + xy.se };
 
            //방벽으로 막혔다면 스킵
            if (state[new_p.fi][new_p.se] == '#')continue;
 
            //0~9 이미 들어있다면 그걸 바탕으로 가기
            if ('0' <= state[new_p.fi][new_p.se] &&
                state[new_p.fi][new_p.se] <= '9') {
                int new_number = state[new_p.fi][new_p.se] - '0';
                int new_cost = now_cost + new_number;
                if (new_cost < visit_cost[new_p.fi][new_p.se]) {
                    visit_cost[new_p.fi][new_p.se] = new_cost;
                    track_state[new_p.fi][new_p.se] = now_p;
                    arr.push({ new_p,new_cost });
                }
                continue;
            }
 
            //.일 경우 dot_num 설정한거 그대로 쓰기
            int new_number = dot_num;
            int new_cost = now_cost + new_number;
            if (new_cost < visit_cost[new_p.fi][new_p.se]) {
                visit_cost[new_p.fi][new_p.se] = new_cost;
                track_state[new_p.fi][new_p.se] = now_p;
                arr.push({ new_p,new_cost });
            }
            continue;
        }
    }
 
    if (visit_cost[e.fi][e.se] == nINF) {
        cout << -1;
        exit(0);
    }
 
    ans = visit_cost[e.fi][e.se];
    intint h = e;
    while (h.fi != -1) {
        track.push_back(h);
        h = track_state[h.fi][h.se];
    }
    return { ans,track };
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 752; i++) {
        for (int j = 0; j < 752; j++) {
            state[i][j] = '#';
        }
    }
 
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> state[i][j];
        }
    }
 
    intint start_p, end_p;
    cin >> start_p.fi >> start_p.se >> end_p.fi >> end_p.se;
 
    int need_dist;
    cin >> need_dist;
 
    int min_cost, max_cost;
    vector<intint>min_track, max_track;
 
    {
        auto h = cal(start_p, end_p, 0);
        min_cost = h.fi;
        min_track = move(h.se);
    }
 
    {
        auto h = cal(start_p, end_p, 9);
        max_cost = h.fi;
        max_track = move(h.se);
    }
 
    //cout<<min_track.size()<<"," << max_track.size() << "생김.\n";
    if (need_dist < min_cost || max_cost < need_dist) {
        cout << -1;
        return 0;
    }
 
    vector<intint>dot_change;
 
    while (need_dist - 9 > min_cost) {
        dot_change.clear();
        for (intint p : min_track) {
            if (state[p.fi][p.se] == '.') {
                dot_change.push_back(p);
                state[p.fi][p.se] = '9';
            }
        }
        auto h = cal(start_p, end_p, 0);
        min_cost = h.fi;
        min_track = move(h.se);
    }
 
    for (intint p : dot_change) {
        state[p.fi][p.se] = '.';
    }
 
    {
        auto h = cal(start_p, end_p, 0);
        min_cost = h.fi;
        min_track = move(h.se);
    }
 
    while (need_dist - 9 > min_cost) {
        min_track.pop_back();//s위치 제거
        ll left_dist = need_dist - min_cost;
        for (intint p : min_track) {
            if (state[p.fi][p.se] == '.' && left_dist > 9) {
                left_dist -= 9;
                state[p.fi][p.se] = '9';
            }
        }
        assert(left_dist <= 9);
        auto h = cal(start_p, end_p, 0);
        min_cost = h.fi;
        min_track = move(h.se);
    }
    state[start_p.fi][start_p.se] = '0' + (need_dist - min_cost);
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (state[i][j] == '.')cout << 0;
            else cout << state[i][j];
        }
        cout << "\n";
    }
}

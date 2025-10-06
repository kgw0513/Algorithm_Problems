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

char rotation[1100005];

//위우하좌
intint dxdy[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int n, m;

bool MoveSnake(deque<intint>& snake,set<intint>&visit_state, set<intint>& fruit_eat,int move_arrow) {
    intint snake_head = snake.front();
    
    intint next_p = { snake_head.fi + dxdy[move_arrow].fi,snake_head.se + dxdy[move_arrow].se };

    if (next_p.fi > n)next_p.fi = 1;
    else if (next_p.fi < 1)next_p.fi = n;

    if (next_p.se > m)next_p.se = 1;
    else if (next_p.se < 1)next_p.se = m;

    intint snake_tail = snake.back();
    visit_state.erase(snake_tail);
    
    if (visit_state.find(next_p) != visit_state.end()) {
        return false;
    }

    snake.pop_back();

    //cout << snake_head.fi << "," << snake_head.se << "마지막 위치.\n";
    if ((next_p.fi + next_p.se) % 2 == 1 && fruit_eat.find(next_p)==fruit_eat.end()) {
        //cout << next_p.fi << "," << next_p.se << "들.\n";
        fruit_eat.insert(next_p);

        snake.push_front(next_p);
        visit_state.insert(next_p);

        snake.push_back(snake_tail);
        visit_state.insert(snake_tail);
    }
    else {
        snake.push_front(next_p);
        visit_state.insert(next_p);
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int loop=1;loop<=t;loop++){
        int s, a;
        char b;
        cin >> s >> n >> m;

        fill(rotation, rotation + 1100005, 'X');
        deque<intint>snake;
        set<intint>visit_state;
        set<intint>fruit_eat;
        int move_arrow = 1;

        snake.push_back({ 1,1 });
        visit_state.insert({ 1,1 });

        while (s--) {
            cin >> a >> b;
            rotation[a] = b;
        }

        for (int timer = 1; timer < 1100005; timer++) {
            //cout << timer << ":" << move_arrow << "중.\n";
            if (!MoveSnake(snake, visit_state, fruit_eat, move_arrow)) {
                break;
            }

            if (rotation[timer] == 'X')continue;

            if (rotation[timer] == 'L')move_arrow += 3;
            else move_arrow++;

            move_arrow %= 4;
        }

        //for (intint& h : snake) {
        //    cout << h.fi << "," << h.se << "<->";
        //}
        //cout << "\n";
        cout << "Case #" << loop << ": " << snake.size() << "\n";
    }
}
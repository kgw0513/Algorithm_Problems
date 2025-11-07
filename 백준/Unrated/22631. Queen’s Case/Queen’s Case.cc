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

enum class State : int {
    Draw = 0,
    QueenWin = 1,
    ArmyWin = 2
};

//[queen.x][queen.y][army.x][army.y]=State
State dp[32][32][32][32][2];
char board[32][32];

//가만히 있는것도 포함해야 해서
//intint dxdy[5] = { {-1,0},{1,0},{0,-1},{0,1},{0,0} };

intint dxdy[5] = { {0,1},{1,0},{0,-1},{-1,0},{0,0} };

string print_ans[3];

queue<pair<int2_int2, bool>>arr;

void cal(const intint queen, const intint army, const bool queen_turn) {
    bool can_draw = false;
    if (queen_turn) {
        for (intint& xy : dxdy) {
            intint new_queen = { queen.fi + xy.first,queen.se + xy.se };
            if (board[new_queen.fi][new_queen.se] == '#')continue;
            State next_State = dp[new_queen.fi][new_queen.se][army.fi][army.se][!queen_turn];
            //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "인 여왕이 " << new_queen.fi << "," << new_queen.se << "로 이동 가능 : " << int(next_State) << "\n";
            if (next_State == State::QueenWin) {
                arr.push({ {queen,army},queen_turn });
                //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "인 여왕은 항상 이긴다.\n";
                dp[queen.fi][queen.se][army.fi][army.se][queen_turn] = State::QueenWin; //여왕이 이길 길 찾으면 그냥 바로 반환
                return;
            }
            if (next_State == State::Draw)can_draw = true;
        }

        if (!can_draw) {//여왕이 이길 길은 못찾았고 draw방법도 없을때
            arr.push({ {queen,army},queen_turn });
            //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "인 여왕은 항상 진다.\n";
            dp[queen.fi][queen.se][army.fi][army.se][queen_turn] = State::ArmyWin;
            return;
        }


        //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "여왕 무승부\n";
        return;
    }

    //army가 결정

    for (intint& xy : dxdy) {
        intint new_army = { army.fi + xy.first,army.se + xy.se };
        if (board[new_army.fi][new_army.se] == '#')continue;
        State next_State = dp[queen.fi][queen.se][new_army.fi][new_army.se][!queen_turn];
        //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "인 army가 " << new_army.fi << "," << new_army.se << "로 이동 가능 : " << int(next_State) << "\n";
        if (next_State == State::ArmyWin) {
            arr.push({ {queen,army},queen_turn });
            //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "인 army는 항상 이긴다.\n";
            dp[queen.fi][queen.se][army.fi][army.se][queen_turn] = State::ArmyWin; //군대가 이기는 길 찾으면 바로 성공
            return;
        }
        if (next_State == State::Draw)can_draw = true;
    }

    if (!can_draw) {//군대가 이길 길은 못찾고 현재 draw방법이 없을때
        arr.push({ {queen,army},queen_turn });
        //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "인 army는 항상 진다.\n";
        dp[queen.fi][queen.se][army.fi][army.se][queen_turn] = State::QueenWin;
        return;
    }
    //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "army 무승부\n";
}

void bfs() {
    while (arr.size()) {
        intint queen = arr.front().fi.fi;
        intint army = arr.front().fi.se;
        bool queen_turn = arr.front().se;
        arr.pop();

        if (!queen_turn) {
            for (intint& xy : dxdy) {
                intint new_queen = { queen.fi + xy.fi,queen.se + xy.se };
                if (board[new_queen.fi][new_queen.se] == '#')continue;
                State next_State = dp[new_queen.fi][new_queen.se][army.fi][army.se][!queen_turn];
                //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "에서 ";
                //cout << new_queen.fi << "," << new_queen.se << "/" << army.fi << "," << army.se << " 중.1\n";

                if (next_State != State::Draw)continue;
                //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "에서 ";
                //cout << new_queen.fi << "," << new_queen.se << "/" << army.fi << "," << army.se << " 탐색 시작.1\n";

                cal(new_queen, army, !queen_turn);
            }
        }
        else {
            for (intint& xy : dxdy) {
                intint new_army = { army.fi + xy.fi,army.se + xy.se };
                if (board[new_army.fi][new_army.se] == '#')continue; 
                State next_State = dp[queen.fi][queen.se][new_army.fi][new_army.se][!queen_turn];
                //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "에서 ";
                //cout << queen.fi << "," << queen.se << "/" << new_army.fi << "," << new_army.se << " 중.2\n";
                if (next_State != State::Draw)continue;
                //cout << queen.fi << "," << queen.se << "/" << army.fi << "," << army.se << "에서 ";
                //cout << queen.fi << "," << queen.se << "/" << new_army.fi << "," << new_army.se << " 탐색 시작.2\n";
                cal(queen, new_army, !queen_turn);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //답 설정
    print_ans[0] = "Queen can not escape and Army can not catch Queen.";
    print_ans[1] = "Queen can escape.";
    print_ans[2] = "Army can catch Queen.";

    //초기화
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= 31; j++) {
            board[i][j] = '#';
        }
    }

    for (int a = 0; a < 32; a++) {
        for (int b = 0; b < 32; b++) {
            for (int c = 0; c < 32; c++) {
                for (int d = 0; d < 32; d++) {
                    for (int e = 0; e < 2; e++) {
                        dp[a][b][c][d][e] = State::Draw;
                    }
                }
            }
        }
    }

    //입력
    int n, m;
    intint queen, army;
    char w;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w;
            if (w == 'Q') {
                queen = { i,j };
                board[i][j] = '.';
            }
            else if (w == 'A') {
                army = { i,j };
                board[i][j] = '.';
            }
            else board[i][j] = w;
        }
    }

    //bfs에 넣을 확정 애들
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '#')continue;
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++) {
                    if (board[x][y] == '#')continue;
                    if (i == x && j == y) {
                        //cout << i << "," << j << "/" << x << "," << y << "/" << 0 << "넣음.\n";
                        arr.push({ {{i,j},{x,y}},true });
                        dp[i][j][x][y][1] = State::ArmyWin;
                        //cout << i << "," << j << "/" << x << "," << y << "/" << 1 << "넣음.\n";
                        arr.push({ {{i,j},{x,y}},false });
                        dp[i][j][x][y][0] = State::ArmyWin;
                    }
                    else if (board[i][j] == 'E') {
                        //cout << i << "," << j << "/" << x << "," << y << "/" << 0 << "넣음.\n";
                        arr.push({ {{i,j},{x,y}},true });
                        dp[i][j][x][y][1] = State::QueenWin;
                    }
                }
            }
        }
    }
    //bfs를 통한 dp전처리
    bfs();

    cout << print_ans[static_cast<int>(dp[queen.fi][queen.se][army.fi][army.se][1])];
}
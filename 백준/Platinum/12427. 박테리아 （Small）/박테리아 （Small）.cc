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

int state[52][22][22];
intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

bool Bipartite_dfs(int A_num, vector<bool>& A_visit, vector<int>& B_rem, vector<vector<int>>& lines, const int& num) {
    if (A_visit[A_num])return false;
    A_visit[A_num] = true;

    for (int B_num : lines[A_num]) {
        if (B_rem[B_num] == 0) {
            B_rem[B_num] = A_num;
            return true;
        }
        if (Bipartite_dfs(B_rem[B_num], A_visit, B_rem, lines, num)) {
            B_rem[B_num] = A_num;
            return true;
        }
    }

    return false;
}

int Bipartite(vector<int>& A, vector<int>& B, vector<vector<int>>& lines, int num) {
    vector<int>B_rem(num + 1, 0);

    int ans = 0;
    for (int& A_num : A) {
        vector<bool>A_visit(num + 1, false);
        if (Bipartite_dfs(A_num, A_visit, B_rem, lines, num))ans++;
    }

    return ans;
}

void Setting_Bipartite(vector<int>& A, vector<int>& B, vector<vector<int>>& lines, int num) {
    vector<bool>visit(num + 1, false);

    for (int Node = 1; Node <= num; Node++) {
        if (visit[Node])continue;
        visit[Node] = true;

        queue<int>arr;
        arr.push(Node);

        for (int i = 1; !arr.empty(); i++) {
            int size = arr.size();
            while (size--) {
                int p = arr.front();
                arr.pop();
                if (i % 2 == 1)A.push_back(p);
                else B.push_back(p);
                for (int& np : lines[p]) {
                    if (visit[np])continue;
                    visit[np] = true;
                    arr.push(np);
                }
            }
        }
    }

    //참고로 이분 그래프로 홀수 짝수 명확하게 나눠진다.
}

void fill_num(const int deep, intint p, const int num) {
    queue<intint>arr;
    arr.push(p);
    state[deep][p.fi][p.se] = num;
    while (!arr.empty()) {
        p = arr.front();
        arr.pop();
        for (intint xy : dxdy) {
            intint new_p = { p.fi + xy.fi,p.se + xy.se };
            if (state[deep][new_p.fi][new_p.se] != 0)continue;
            state[deep][new_p.fi][new_p.se] = num;
            arr.push(new_p);
        }
    }
}

int test() {
    for (int a = 0; a < 52; a++) {
        for (int b = 0; b < 22; b++) {
            for (int c = 0; c < 22; c++) {
                state[a][b][c] = -1;
            }
        }
    }

    int give_num = 0;

    int n, m, k;
    cin >> n >> m >> k;

    for (int deep = 1; deep <= k; deep++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char w;
                cin >> w;
                if (w == '#')state[deep][i][j] = -1;
                else state[deep][i][j] = 0;
            }
        }
    }

    for (int deep = 1; deep <= k; deep++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (state[deep][i][j] != 0)continue;
                fill_num(deep, { i,j }, ++give_num);
            }
        }
    }

    //cout << "입력 상태.\n";
    //for (int deep = 1; deep <= k; deep++) {
    //    for (int i = 1; i <= n; i++) {
    //        for (int j = 1; j <= m; j++) {
    //            cout << state[deep][i][j] << " ";
    //        }
    //        cout << "\n";
    //    }
    //    cout << "\n";
    //}

    if (give_num == 0) { //박테리아 둘 곳 없으면 0 반환
        return 0;
    }

    set<intint>gather_lines;
    for (int deep = 1; deep <= k; deep++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (state[deep][i][j] == -1)continue;
                if (state[deep - 1][i][j] != -1) {
                    gather_lines.insert({ state[deep - 1][i][j] ,state[deep][i][j] });
                    gather_lines.insert({ state[deep][i][j] ,state[deep - 1][i][j] });
                }
                if (state[deep + 1][i][j] != -1) {
                    gather_lines.insert({ state[deep + 1][i][j] ,state[deep][i][j] });
                    gather_lines.insert({ state[deep][i][j] ,state[deep + 1][i][j] });
                }
            }
        }
    }

    vector<vector<int>>lines(give_num + 1);
    for (const intint& w : gather_lines) {
        lines[w.fi].push_back(w.se);
    }

    vector<int>A, B;
    Setting_Bipartite(A, B, lines, give_num);

    return give_num - Bipartite(A, B, lines, give_num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": " << test() << "\n";
    }
}
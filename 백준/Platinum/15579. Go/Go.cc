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

//* 포켓몬 번호가 0이라는건 없다는 뜻으로 처리하기.
// 첫번째 index : 이제 갈 왼쪽 포켓몬
// 두번째 index : 이제 갈 오른쪽 포켓몬
// 세번째 index : 마지막 이동이 이제 갈 왼쪽 포켓몬 옆인지(0), 이제 갈 오른쪽 포켓몬 옆인지(1)
// 네번째 index : 걸린시간 (최대 2000시간 쓴다 가정)
// 저장 값 : 최대가 되는 사탕 갯수
int arr[105][105][2][2005];
bool visit[105][105][2][2005];

intint pokemon[105];

int house2pokemon[1005];
int pokemon2house[105];

int pokemon2leftpokemon[105]; //현 포켓몬 -> 다음 왼쪽 포켓몬 번호
int pokemon2rightpokemon[105]; //현 포켓몬 -> 다음 오른쪽 포켓몬 번호

int dfs(int poke_s, int poke_e, int now_p,bool is_left,int cur_time) {
    if (cur_time > 2000)return 0;

    if (visit[poke_s][poke_e][is_left][cur_time])return arr[poke_s][poke_e][is_left][cur_time];
    visit[poke_s][poke_e][is_left][cur_time] = true;

    if (poke_s == 0 && poke_e == 0)return arr[poke_s][poke_e][is_left][cur_time] = 0;

    if (poke_s != 0) {
        int next_p = pokemon2house[poke_s];
        int next_time = cur_time + abs(now_p - next_p);
        arr[poke_s][poke_e][is_left][cur_time] = max(arr[poke_s][poke_e][is_left][cur_time],dfs(pokemon2leftpokemon[poke_s], poke_e, next_p, true, next_time) + (next_time < pokemon[poke_s].se ? pokemon[poke_s].fi : 0));
    }

    if (poke_e != 0) {
        int next_p = pokemon2house[poke_e];
        int next_time = cur_time + abs(next_p - now_p);
        arr[poke_s][poke_e][is_left][cur_time] = max(arr[poke_s][poke_e][is_left][cur_time], dfs(poke_s, pokemon2rightpokemon[poke_e], next_p, false, next_time) + (next_time < pokemon[poke_e].se ? pokemon[poke_e].fi : 0));
    }
    
    //cout << poke_s << "~" << poke_e << "/ 왼 : " << is_left << " / 시간 : " << cur_time << " = " << arr[poke_s][poke_e][is_left][cur_time] << "??\n";
    return arr[poke_s][poke_e][is_left][cur_time];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    int n, k, m, a, b, c;
    cin >> n >> k >> m;
    for(int num=1;num<=m;num++){
        cin >> a >> b >> c;
        if (a == k) { //시작위치에 포켓몬 있으면 그냥 잡으면 되니 처리 제외.
            ans += b;
            continue;
        }
        pokemon[num] = { b,c };
        house2pokemon[a] = num;
        pokemon2house[num] = a;
    }

    {
        stack<int>brr;
        for (int i = 1; i <= n; i++) {
            if (house2pokemon[i] == 0)continue;
            if (!brr.empty()) {
                int s = brr.top();
                int e = house2pokemon[i];
                
                pokemon2leftpokemon[e] = s;
                pokemon2rightpokemon[s] = e;
            }
            brr.push(house2pokemon[i]);
        }
    }

    intint start_set = { 0,0 };
    for (int i = k; i >= 1; i--) {
        if (house2pokemon[i] != 0) {
            start_set.fi = house2pokemon[i];
            break;
        }
    }
    for (int i = k; i <= n; i++) {
        if (house2pokemon[i] != 0) {
            start_set.se = house2pokemon[i];
            break;
        }
    }

    //cout << start_set.fi << "~" << start_set.se << "!!\n";
    ans += dfs(start_set.fi, start_set.se, k, true, 0);

    cout << ans;
}
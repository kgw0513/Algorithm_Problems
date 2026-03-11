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

bool can_input[10];
int state[2][1000002]; //[0 : =안눌렀을때, 1: =눌렀을때][현 위치]

string cal() {
    fill(state[0], state[0] + 1000002, INF);
    fill(state[1], state[1] + 1000002, INF);
    vector<int>num;

    for (bool& w : can_input) {
        cin >> w;
    }

    for (int i = 1; i <= 1000000; i++) {
        string h = to_string(i);
        bool can_use = true;
        for (char h2 : h) {
            if (!can_input[h2 - '0']) {
                can_use = false;
                break;
            }
        }

        if (!can_use)continue;
        num.push_back(i);
        state[0][i] = to_string(i).size();
        state[1][i] = state[0][i] + 1;
    }

    int x;
    cin >> x;

    for (int i = 1; i < x; i++) {
        if (state[0][i] != INF) {
            for (int n : num) {
                if (i * n > x && stoi(to_string(i) + to_string(n)) > x)break;

                //= 안누른부분은 곱하기 진행중이거나 이미 한번 덧붙였으므로 함부로 덧붙이면 안된다

                //곱할때
                if (i * n <= x) {
                    state[0][i * n] = min(state[0][i * n], int(state[0][i] + to_string(n).size() + 1));
                }

                //곱하고 =누를때
                if (i * n <= x) {
                    state[1][i * n] = min(state[1][i * n], int(state[0][i] + to_string(n).size() + 2));
                }
            }
            state[1][i] = min(state[1][i], state[0][i] + 1);
        }
    }
    
    return (state[1][x] == INF ? "Impossible" : to_string(state[1][x]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cout << "Case #" << test << ": " << cal() << "\n";
    }
}
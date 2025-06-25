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
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
constexpr unsigned long long MOD3 = 998244353;
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

int dp[12][48][48][48][48];

int score[48] = {
    0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,0,0,0,0,
    13,16,19,0,0,0,0,0,28,27,26,0,0,0,0,0,22,24,25,30,35,40,0
};

inline bool board_out(int p) {
    if (20 <= p && p <= 24)return true;
    if (28 <= p && p <= 32)return true;
    if (36 <= p && p <= 40)return true;
    return false;
}

inline int fix_p(int p) {
    if (20 <= p && p <= 24) {
        int h = p - 20;
        p = 46 + h;
    }
    if (28 <= p && p <= 32) {
        int h = p - 28;
        p = 43 + h;
    }
    if (36 <= p && p <= 40) {
        int h = p - 36;
        p = 43 + h;
    }
    return min(47,p);
}

inline int ori_p(int p) {
    if (p == 5)return 24;
    if (p == 10)return 40;
    if (p == 15)return 32;
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr(10);
    for (int& h : arr) {
        cin >> h;
    }

    dp[0][0][0][0][0] = 1;
    int ans = 1;
    for (int i = 0; i < 10; i++) {
        for (int p1 = 0; p1 < 48; p1++) {
            if (board_out(p1))continue;
            for (int p2 = 0; p2 < 48; p2++) {
                if (board_out(p2))continue;
                for (int p3 = 0; p3 < 48; p3++) {
                    if (board_out(p3))continue;
                    for (int p4 = 0; p4 < 48; p4++) {
                        if (board_out(p4))continue;
                        if (dp[i][p1][p2][p3][p4] == 0)continue;

                        if (p1 != 0 && p1 != 47) {
                            if (p1 == p2 || p1 == p3 || p1 == p4)continue;
                        }

                        if (p2 != 0 && p2 != 47) {
                            if (p2 == p3 || p2 == p4)continue;
                        }

                        if (p3 != 0 && p3 != 47) {
                            if (p3 == p4)continue;
                        }

                        int origin_p1 = ori_p(p1);
                        int origin_p2 = ori_p(p2);
                        int origin_p3 = ori_p(p3);
                        int origin_p4 = ori_p(p4);

                        int new_p1 = fix_p(origin_p1 + arr[i]);
                        int new_p2 = fix_p(origin_p2 + arr[i]);
                        int new_p3 = fix_p(origin_p3 + arr[i]);
                        int new_p4 = fix_p(origin_p4 + arr[i]);

                        if (new_p1 == 0 || new_p1 == 47 || (new_p1 != p2 && new_p1 != p3 && new_p1 != p4))
                            dp[i + 1][new_p1][p2][p3][p4] = max(dp[i + 1][new_p1][p2][p3][p4], dp[i][p1][p2][p3][p4] + score[new_p1]);
                        
                        if (new_p2 == 0 || new_p2 == 47 || (new_p2 != p1 && new_p2 != p3 && new_p2 != p4))
                            dp[i + 1][p1][new_p2][p3][p4] = max(dp[i + 1][p1][new_p2][p3][p4], dp[i][p1][p2][p3][p4] + score[new_p2]);
                        
                        if (new_p3 == 0 || new_p3 == 47 || (new_p3 != p2 && new_p3 != p1 && new_p3 != p4))
                            dp[i + 1][p1][p2][new_p3][p4] = max(dp[i + 1][p1][p2][new_p3][p4], dp[i][p1][p2][p3][p4] + score[new_p3]);
                        
                        if (new_p4 == 0 || new_p4 == 47 || (new_p4 != p2 && new_p4 != p3 && new_p4 != p1))
                            dp[i + 1][p1][p2][p3][new_p4] = max(dp[i + 1][p1][p2][p3][new_p4], dp[i][p1][p2][p3][p4] + score[new_p4]);
                    }
                }
            }
        }
    }

    for (int p1 = 0; p1 < 48; p1++) {
        if (board_out(p1))continue;
        for (int p2 = 0; p2 < 48; p2++) {
            if (board_out(p2))continue;
            for (int p3 = 0; p3 < 48; p3++) {
                if (board_out(p3))continue;
                for (int p4 = 0; p4 < 48; p4++) {
                    if (board_out(p4))continue;

                    ans = max(ans, dp[10][p1][p2][p3][p4]);
                }
            }
        }
    }
    cout << ans-1;
}

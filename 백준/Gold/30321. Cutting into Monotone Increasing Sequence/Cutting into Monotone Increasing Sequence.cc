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

int dp[100033][22];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 100033; i++) {
        for (int j = 0; j < 22; j++) {
            dp[i][j] = nINF;
        }
    }

    string x;
    unsigned long long b;
    cin >> x >> b;
    if(x=="0"){
        cout<<0;
        return 0;
    }

    string a = to_string(b);
    int s_p = x.size() - 1;
    x += a;
    dp[s_p+1][a.size()] = 1;
    
    for (int i = s_p; i >= 0; i--) {
        __int128 j_num = 0;
        if (x[i] == '0')continue;

        for (int j = 0; j < 20; j++) {
            int p_j_s = i;
            int p_j_e = i + j;
            if (p_j_e >= x.size())break;
            j_num = j_num * 10 + (x[p_j_e] - '0');
            __int128 k_num = 0;
            for (int k = 0; k < 20; k++) {
                int p_k_s = p_j_e + 1;
                int p_k_e = p_j_e + 1 + k;
                if (p_k_e >= x.size())break;
                k_num = k_num * 10 + (x[p_k_e] - '0');
                // cout<<i<<","<<j<<","<<k<<"/"<<ll(j_num)<<","<<ll(k_num)<<"시도\n";
                if (j_num <= k_num && dp[p_j_e + 1][p_k_e - p_k_s + 1] < nINF) {
                    // cout<<"성공!\n";
                    dp[i][p_j_e - p_j_s + 1] = min(dp[i][p_j_e - p_j_s + 1], dp[p_j_e + 1][p_k_e - p_k_s + 1] + 1);
               }
            }
        }
    }

    int ans = dp[0][20];
    for (int i = 1; i <= 20; i++) {
        ans = min(ans, dp[0][i]);
    }
    if(ans>=nINF){
        cout<<"NO WAY";
        return 0;
    }
    cout << ans-2;
}
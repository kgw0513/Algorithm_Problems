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

string arr[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    arr[1][1] = "1";
    arr[1][2] = "2";
    arr[1][3] = "3";
    arr[1][4] = "4";
    arr[1][5] = "5";
    arr[1][6] = "6";
    arr[1][7] = "7";
    arr[1][8] = "8";
    arr[1][9] = "9";
    arr[2][1] = "0";
    arr[2][2] = "105263157894736842";
    arr[2][3] = "157894736842105263";
    arr[2][4] = "210526315789473684";
    arr[2][5] = "263157894736842105";
    arr[2][6] = "315789473684210526";
    arr[2][7] = "368421052631578947";
    arr[2][8] = "421052631578947368";
    arr[2][9] = "473684210526315789";
    arr[3][1] = "0";
    arr[3][2] = "0";
    arr[3][3] = "1034482758620689655172413793";
    arr[3][4] = "1379310344827586206896551724";
    arr[3][5] = "1724137931034482758620689655";
    arr[3][6] = "2068965517241379310344827586";
    arr[3][7] = "2413793103448275862068965517";
    arr[3][8] = "2758620689655172413793103448";
    arr[3][9] = "3103448275862068965517241379";
    arr[4][1] = "0";
    arr[4][2] = "0";
    arr[4][3] = "0";
    arr[4][4] = "102564";
    arr[4][5] = "128205";
    arr[4][6] = "153846";
    arr[4][7] = "179487";
    arr[4][8] = "205128";
    arr[4][9] = "230769";
    arr[5][1] = "0";
    arr[5][2] = "0";
    arr[5][3] = "0";
    arr[5][4] = "0";
    arr[5][5] = "102040816326530612244897959183673469387755";
    arr[5][6] = "122448979591836734693877551020408163265306";
    arr[5][7] = "142857";
    arr[5][8] = "163265306122448979591836734693877551020408";
    arr[5][9] = "183673469387755102040816326530612244897959";
    arr[6][1] = "0";
    arr[6][2] = "0";
    arr[6][3] = "0";
    arr[6][4] = "0";
    arr[6][5] = "0";
    arr[6][6] = "1016949152542372881355932203389830508474576271186440677966";
    arr[6][7] = "1186440677966101694915254237288135593220338983050847457627";
    arr[6][8] = "1355932203389830508474576271186440677966101694915254237288";
    arr[6][9] = "1525423728813559322033898305084745762711864406779661016949";
    arr[7][1] = "0";
    arr[7][2] = "0";
    arr[7][3] = "0";
    arr[7][4] = "0";
    arr[7][5] = "0";
    arr[7][6] = "0";
    arr[7][7] = "1014492753623188405797";
    arr[7][8] = "1159420289855072463768";
    arr[7][9] = "1304347826086956521739";
    arr[8][1] = "0";
    arr[8][2] = "0";
    arr[8][3] = "0";
    arr[8][4] = "0";
    arr[8][5] = "0";
    arr[8][6] = "0";
    arr[8][7] = "0";
    arr[8][8] = "1012658227848";
    arr[8][9] = "1139240506329";
    arr[9][1] = "0";
    arr[9][2] = "0";
    arr[9][3] = "0";
    arr[9][4] = "0";
    arr[9][5] = "0";
    arr[9][6] = "0";
    arr[9][7] = "0";
    arr[9][8] = "0";
    arr[9][9] = "10112359550561797752808988764044943820224719";

    int n, k;
    cin >> n >> k;
    cout << arr[n][k];
}
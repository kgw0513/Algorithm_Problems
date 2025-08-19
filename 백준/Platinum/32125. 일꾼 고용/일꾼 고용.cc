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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

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

ll cal(ll n, ll k) {
    vector<ll>work_type(n);
    vector<ll>work_effic(n);
    map<ll, ordered_set>arr;
    ll type_diff = 0, effic_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> work_type[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> work_effic[i];
        if (work_type[i] == 1) {
            type_diff++;
            effic_sum += work_effic[i];
        }
        else {
            type_diff--;
            effic_sum -= work_effic[i];
        }
    }

    ll ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        
        arr[type_diff].insert(effic_sum);
        // cout<<type_diff<<"에 "<<effic_sum<<"넣기.\n";

        if (work_type[i] == 1) {
            type_diff--;
            effic_sum -= work_effic[i];
        }
        else {
            type_diff++;
            effic_sum += work_effic[i];
        }
        
        // cout << type_diff << "," << effic_sum << "상태.\n";
        ll s = arr[type_diff].order_of_key(effic_sum-k);
        ll e = arr[type_diff].order_of_key(effic_sum+k+1);
        // cout << i << "에서 " << s << "보다 크거나 같고, " << e << "보다 작게 가능.\n";
        // cout<<arr[-type_diff].size()<<"개 있음.\n";
        ans+=e-s;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << cal(n, k) << "\n";
    }
}
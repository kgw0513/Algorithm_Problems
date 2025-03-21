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
constexpr unsigned long long MOD1 = 1000000363;
constexpr unsigned long long MOD2 = 1000000007;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, w, find_dist;
    cin >> n;
    ll_ll ans = { lINF,0 };
    map<ll, ll>arr;
    for (int i = 0; i < n; i++) {
        cin >> w;
        arr[w]++;
    }
    cin >> find_dist;

    vector<ll>brr;
    for (auto h : arr) {
        brr.push_back(h.fi);
    }

    for (int i = 0; i < brr.size(); i++) {
        int h = lower_bound(brr.begin(), brr.end(), find_dist - brr[i]) - brr.begin();
        for (int j = -1; j <= 1; j++) {
            int new_h = h + j;
            if (!(0 <= new_h && new_h < brr.size()))
                continue;

            if (i == new_h && arr[brr[i]]>=2) {
                ans.fi = min(ans.fi, abs(find_dist - brr[i] * 2));
            }
            else if(i!=new_h){
                ans.fi = min(ans.fi, abs(find_dist - (brr[i] + brr[new_h])));
            }
        }
    }

    ans.se = 0;
    for (auto h : arr) {
        if (h.fi * 2 == find_dist + ans.fi || h.fi * 2 == find_dist - ans.fi) {
            //cout<<h.fi<<","<<h.fi<<"=0>" << h.se << "*" << h.se - 1 << "/2\n";
            ans.se += h.se * (h.se - 1) / 2;
        }
        //cout << h.fi << "에서.\n";
        if (find_dist + ans.fi - h.fi < h.fi) {
            //cout << find_dist + ans.fi - h.fi << "," << h.fi << " =1> " << arr[find_dist + ans.fi - h.fi] << "*" << h.se << "\n";
            ans.se += arr[find_dist + ans.fi - h.fi] * h.se;
        }
        if (find_dist - ans.fi - h.fi < h.fi && ans.fi!=0) {
            //cout << find_dist - ans.fi - h.fi << "," << h.fi << " =2> " << arr[find_dist - ans.fi - h.fi] << "*" << h.se << "\n";
            ans.se += arr[find_dist - ans.fi - h.fi] * h.se;
        }
    }
    cout << ans.se;
}
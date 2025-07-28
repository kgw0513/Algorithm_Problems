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
 
int now_tier;
namespace Member {
    bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if (abs(a.se - now_tier) != abs(b.se - now_tier))return abs(a.se - now_tier) < abs(b.se - now_tier);
        for (int i = 0; i < min(a.fi.size(), b.fi.size()); i++) {
            if (a.fi[i] != b.fi[i])return a.fi[i] < b.fi[i];
        }
        return a.fi.size() < b.fi.size();
    }
 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<string, int>>arr(n);
    for (pair<string, int>& h : arr) {
        cin >> h.fi >> h.se;
    }
    cin >> n;
    unordered_map<string, int>member_to_int;
    vector<pair<string, int>>member_algo_suki[10];
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a >> now_tier;
        member_to_int[a] = i;
        member_algo_suki[i] = arr;
        sort(member_algo_suki[i].begin(), member_algo_suki[i].end(), Member::cmp);
    }
    cin >> n;
    string w;
    cin.ignore();
 
    int now_call_member = -1;
    while (n--) {
        getline(cin, w);
        if (w.back() == '!') {
            string member_name = "";
            for (char a : w) {
                if (a == ' ')break;
                member_name += a;
            }
            if (member_to_int.find(member_name) == member_to_int.end())return -1;
            now_call_member = member_to_int[member_name];
            cout << "hai!\n";
            continue;
        }
        assert(now_call_member != -1);
 
        cout << member_algo_suki[now_call_member][1].first << " yori mo " <<
            member_algo_suki[now_call_member][0].first << "\n";
    }
}

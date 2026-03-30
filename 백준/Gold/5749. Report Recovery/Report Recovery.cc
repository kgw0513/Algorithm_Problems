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

int p_count;
//{{이름,숫자},값 저장 역할}
vector<pair<pair<string, string>, vector<int>>>arr;
map<int, vector<vector<int>>>brr;
stack<string>ans;

bool cal(int p1, int p2, int p3) {
    if (p2 >= arr[p1].se.size()) {
        if (p3 < arr[p1].fi.se.size())return false;
        int sum = 0;
        for (int j = 0; j < p_count; j++) {
            sum += arr[p1].se[j];
        }
        if (sum != arr[p1].se.back())return false;
        brr[p1].push_back(arr[p1].se);
        return true;
    }

    bool bs = false;
    for (int i = 0; i < 5; i++) {
        if (p3 + i >= arr[p1].fi.se.size()) {
            continue;
        }
        int state = 0;
        for (int j = p3; j <= p3 + i; j++) {
            state *= 10;
            state += (arr[p1].fi.se[j] - '0');
        }
        if (!(arr[p1].fi.fi.size() == 2 && (arr[p1].fi.fi[0] == 'T' && arr[p1].fi.fi[1] == 'P')) && state >= 1000 && (p2 + 1) != arr[p1].se.size()) {
            continue;
        }
        arr[p1].se[p2] = state;
        bs |= cal(p1, p2 + 1, p3 + i + 1);
        if (arr[p1].fi.se[p3] == '0')break;
    }

    return bs;
}

bool cal2(int p, vector<int>& sum_dp) {
    if (p + 1 == arr.size()) {
        for (vector<int>& bs : brr[p]) {
            bool is_can = true;
            for (int i = 0; i < p_count + 1; i++) {
                if (bs[i] != sum_dp[i]) {
                    is_can = false;
                    break;
                }
            }
            if (!is_can)continue;

            string ah = "";
            ah += arr[p].fi.fi;
            for (int& h : bs) {
                ah += " " + to_string(h);
            }
            ans.push(ah);
            return true;
        }
        return false;
    }

    for (vector<int>& bs : brr[p]) {
        for (int i = 0; i < p_count + 1; i++) {
            sum_dp[i] += bs[i];
        }
        if (cal2(p + 1, sum_dp)) {
            string ah = "";
            ah += arr[p].fi.fi;
            for (int& h : bs) {
                ah += " " + to_string(h);
            }
            ans.push(ah);
            return true;
        }
        for (int i = 0; i < p_count + 1; i++) {
            sum_dp[i] -= bs[i];
        }
    }
    return false;
}

void test() {
    string w;
    cin >> w;
    p_count = 0;
    for (char& h : w) {
        if (h == 'P')p_count++;
    }

    for (int i = 1; i <= p_count; i++) {
        cout << "P" << i << " ";
    }
    cout << "Totals\n";

    arr.clear();
    brr.clear();
    while (1) {
        cin >> w;
        string name = "";
        string number = "";
        for (int i = 0; i < w.size(); i++) {
            if ('0' <= w[i] && w[i] <= '9') {
                number += w[i];
            }
            else {
                name += w[i];
            }
        }
        arr.push_back({ {name,number},vector<int>(p_count + 1,0) });
        if (!cal(arr.size() - 1, 0, 0))exit(-1);
        if (w[0] == 'T' && w[1] == 'P' && ('0' <= w[2] && w[2] <= '9')) {
            break;
        }
    }

    vector<int>sum_dp(p_count + 1, 0);
    if (!cal2(0, sum_dp))exit(-1);
    while (ans.size()) {
        cout << ans.top() << "\n";
        ans.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
    }
}
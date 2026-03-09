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

bool is_not_sosu[10000002] = { 1,1 };
map<int, bitset<1600>>state;
bool used[10002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= sqrt(10000000); i++) {
        for (int j = i * i; j <= 10000000; j += i) {
            is_not_sosu[j] = true;
        }
    }

    int sc = 0;
    vector<int>sosu;
    for (int i = 2; i <= 10000000; i++) {
        if (!is_not_sosu[i])sosu.push_back(i);
    }

    for (int i = 0; i < sosu.size(); i++) {
        int sum = sosu[i];
        for (int c = 1; c < 10000; c++) {
            int j = i + c;
            if (j >= sosu.size())break;
            sum += sosu[j];
            if (sum >= 10000000)break;
            if (is_not_sosu[sum])continue;
            state[sum][c] = 1;
            used[c] = true;
        }
    }

    //for (int i = 0; i < 10000; i++) {
    //    if (used[i]) {
    //        sc++;
    //        cout << i << "이거 썼음!\n";
    //    }
    //}

    //cout<<"총 : "<<sc<<"\n";

    //cout << "들.\n";
    //for (auto h : state) {
    //    if (h.fi == 83) {
    //        for (int i = 0; i < 10000; i++) {
    //            if (h.se[i] == 1)cout << i << "있.\n";
    //        }
    //    }
    //}

    int t, n, w;
    cin >> t;
    for(int test=1;test<=t;test++){
        if (test >= 2)cout << "\n\n";
        cout << "Scenario " << test << ":\n";
        cin >> n;
        bitset<1600>in_state;

        bool is_only_one = true;
        while (n--) {
            cin >> w;
            if (w != 1)is_only_one = false;
            in_state[w-1] = 1;
        }

        if (is_only_one) {
            cout << "2";
            continue;
        }

        bool is_find = false;
        for (const auto &h : state) {
            bitset<1600>cal = h.se & in_state;
            if (cal==in_state) {
                is_find = true;
                cout << h.fi;
                break;
            }
        }

        if (!is_find)return -1;
    }
}
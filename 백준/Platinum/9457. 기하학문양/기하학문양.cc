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
    template <class T>
    inline void hash_combine(std::size_t& seed, const T& v)
    {
        //boost에서 정의한 hash 분포 함수 (근데 최적인지는 몰루)
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    struct default_hash {
        template <class T>
        size_t operator()(const T& n) const {
            size_t seed = 0;
            hash_combine(seed, n);
            return seed;
        }
    };
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& n) const {
            size_t seed = 0;
            hash_combine(seed, n.fi);
            hash_combine(seed, n.se);
            return seed;
        }
    };
    struct vector_hash {
        template<class T>
        size_t operator()(const vector<T>& arr) const {
            size_t seed = 0;
            for (const T& h : arr) {
                hash_combine(seed, h);
            }
            return seed;
        }
    };
    struct deque_hash {
        template<class T>
        size_t operator()(const deque<T>& arr) const {
            size_t seed = 0;
            for (const T& h : arr) {
                hash_combine(seed, h);
            }
            return seed;
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

//[0: 서로 모름 / 1: 서로 알음]
int arr[50002];
int dp[50002];
int brr[50002];

constexpr int MOD = 10007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#pragma region 직사각형 그리드
    arr[1] = 1;
    arr[2] = 4;
    for (int i = 3; i <= 50000; i++) {
        arr[i] = arr[i-1] *4 - arr[i-2];
        arr[i] %= MOD;
        arr[i] += MOD;
        arr[i] %= MOD;
    }
#pragma endregion
#pragma region 원형 그리드
    brr[1] = 1;
    brr[2] = 12;
    dp[1] = 2;
    dp[2] = 7;
    for (int i = 3; i <= 50000; i++) {
        dp[i] = dp[i - 1] * 4 - dp[i - 2];
        dp[i] %= MOD;
        dp[i] += MOD;
        dp[i] %= MOD;
        brr[i] = dp[i] * i - i;
        brr[i] %= MOD;
        brr[i] += MOD;
        brr[i] %= MOD;
    }
#pragma endregion

    int t,w;
    cin >> t;
    while (t--) {
        cin >> w;
        cout << arr[w] << " " << brr[w] << "\n";
    }
}
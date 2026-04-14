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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y;
    cin >> y;
    if(y==1){
        cout<<0;
        return 0;
    }
    stack<int>ans;
    while (y != 0) {
        int sum = 1;
        int i = 1;
        for (i = 1; i <= 9; i++) {
            if (sum * i > y)break;
            sum *= i;
        }
        i--;
        y -= sum;
        ans.push(i);
    }
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}
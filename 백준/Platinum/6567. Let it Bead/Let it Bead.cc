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

unordered_map<intint, int, pair_hash>ans;
deque<uint16_t> state;

void cal(const int& c, const int& s, unordered_set<deque<uint16_t>, deque_hash>& arr) {
    if (state.size() == s) {
        bool already_in = false;
        for (int i = 0; i < s; i++) {
            already_in |= (arr.find(state) != arr.end());
            state.push_back(state.front());
            state.pop_front();
        }
        reverse(state.begin(), state.end());
        for (int i = 0; i < s; i++) {
            already_in |= (arr.find(state) != arr.end());
            state.push_back(state.front());
            state.pop_front();
        }
        reverse(state.begin(), state.end());
        if (already_in)return;
        arr.insert(state);
        //for (int i = 0; i < s; i++) {
        //    cout << state[i] << ",";
        //}
        //cout << "들.\n";
        return;
    }
    for (int i = 0; i < c; i++) {
        state.push_back(i);
        cal(c, s, arr);
        state.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for (int c = 1; c <= 32; c++) {
    //    for (int s =1; s <= 32/c; s++) {
    //        unordered_set<deque<uint16_t>, deque_hash>arr;
    //        state.clear();
    //        //cout << c << "," << s << "수행 중.\n";
    //        cal(c, s, arr);
    //        ans[{c, s}] = arr.size();
    //        cout << "ans[{" << c << "," << s << "}] = " << arr.size() << ";\n";
    //        //cout << c << "," << s << "수행 완. : " << arr.size() << "\n";
    //    }
    //}
    ans[{1, 1}] = 1;
    ans[{1, 2}] = 1;
    ans[{1, 3}] = 1;
    ans[{1, 4}] = 1;
    ans[{1, 5}] = 1;
    ans[{1, 6}] = 1;
    ans[{1, 7}] = 1;
    ans[{1, 8}] = 1;
    ans[{1, 9}] = 1;
    ans[{1, 10}] = 1;
    ans[{1, 11}] = 1;
    ans[{1, 12}] = 1;
    ans[{1, 13}] = 1;
    ans[{1, 14}] = 1;
    ans[{1, 15}] = 1;
    ans[{1, 16}] = 1;
    ans[{1, 17}] = 1;
    ans[{1, 18}] = 1;
    ans[{1, 19}] = 1;
    ans[{1, 20}] = 1;
    ans[{1, 21}] = 1;
    ans[{1, 22}] = 1;
    ans[{1, 23}] = 1;
    ans[{1, 24}] = 1;
    ans[{1, 25}] = 1;
    ans[{1, 26}] = 1;
    ans[{1, 27}] = 1;
    ans[{1, 28}] = 1;
    ans[{1, 29}] = 1;
    ans[{1, 30}] = 1;
    ans[{1, 31}] = 1;
    ans[{1, 32}] = 1;
    ans[{2, 1}] = 2;
    ans[{2, 2}] = 3;
    ans[{2, 3}] = 4;
    ans[{2, 4}] = 6;
    ans[{2, 5}] = 8;
    ans[{2, 6}] = 13;
    ans[{2, 7}] = 18;
    ans[{2, 8}] = 30;
    ans[{2, 9}] = 46;
    ans[{2, 10}] = 78;
    ans[{2, 11}] = 126;
    ans[{2, 12}] = 224;
    ans[{2, 13}] = 380;
    ans[{2, 14}] = 687;
    ans[{2, 15}] = 1224;
    ans[{2, 16}] = 2250;
    ans[{3, 1}] = 3;
    ans[{3, 2}] = 6;
    ans[{3, 3}] = 10;
    ans[{3, 4}] = 21;
    ans[{3, 5}] = 39;
    ans[{3, 6}] = 92;
    ans[{3, 7}] = 198;
    ans[{3, 8}] = 498;
    ans[{3, 9}] = 1219;
    ans[{3, 10}] = 3210;
    ans[{4, 1}] = 4;
    ans[{4, 2}] = 10;
    ans[{4, 3}] = 20;
    ans[{4, 4}] = 55;
    ans[{4, 5}] = 136;
    ans[{4, 6}] = 430;
    ans[{4, 7}] = 1300;
    ans[{4, 8}] = 4435;
    ans[{5, 1}] = 5;
    ans[{5, 2}] = 15;
    ans[{5, 3}] = 35;
    ans[{5, 4}] = 120;
    ans[{5, 5}] = 377;
    ans[{5, 6}] = 1505;
    ans[{6, 1}] = 6;
    ans[{6, 2}] = 21;
    ans[{6, 3}] = 56;
    ans[{6, 4}] = 231;
    ans[{6, 5}] = 888;
    ans[{7, 1}] = 7;
    ans[{7, 2}] = 28;
    ans[{7, 3}] = 84;
    ans[{7, 4}] = 406;
    ans[{8, 1}] = 8;
    ans[{8, 2}] = 36;
    ans[{8, 3}] = 120;
    ans[{8, 4}] = 666;
    ans[{9, 1}] = 9;
    ans[{9, 2}] = 45;
    ans[{9, 3}] = 165;
    ans[{10, 1}] = 10;
    ans[{10, 2}] = 55;
    ans[{10, 3}] = 220;
    ans[{11, 1}] = 11;
    ans[{11, 2}] = 66;
    ans[{12, 1}] = 12;
    ans[{12, 2}] = 78;
    ans[{13, 1}] = 13;
    ans[{13, 2}] = 91;
    ans[{14, 1}] = 14;
    ans[{14, 2}] = 105;
    ans[{15, 1}] = 15;
    ans[{15, 2}] = 120;
    ans[{16, 1}] = 16;
    ans[{16, 2}] = 136;
    ans[{17, 1}] = 17;
    ans[{18, 1}] = 18;
    ans[{19, 1}] = 19;
    ans[{20, 1}] = 20;
    ans[{21, 1}] = 21;
    ans[{22, 1}] = 22;
    ans[{23, 1}] = 23;
    ans[{24, 1}] = 24;
    ans[{25, 1}] = 25;
    ans[{26, 1}] = 26;
    ans[{27, 1}] = 27;
    ans[{28, 1}] = 28;
    ans[{29, 1}] = 29;
    ans[{30, 1}] = 30;
    ans[{31, 1}] = 31;
    ans[{32, 1}] = 32;

    int c, s;
    while (1) {
        cin >> c >> s;
        if (c == 0 && s == 0)break;
        cout << ans[{c, s}] << "\n";
    }
}
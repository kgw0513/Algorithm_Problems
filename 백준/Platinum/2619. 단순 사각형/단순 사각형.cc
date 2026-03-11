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

struct Node {
    intint p = { -1,-1 };
    Node* up_Node = nullptr;
    Node* down_Node = nullptr;
    Node* left_Node = nullptr;
    Node* right_Node = nullptr;
    Node() = default;
};

bool x_sort(int2_int2 a, int2_int2 b) {
    return a.fi.fi < b.fi.fi;
}

bool y_sort(int2_int2 a, int2_int2 b) {
    return a.fi.se < b.fi.se;
}

vector<int2_int2>pin_x;
vector<int2_int2>pin_y;

unordered_map<intint, Node, pair_hash>state;

intint line_cross(int2_int2 x_line, int2_int2 y_line) {
    if (y_line.fi.fi <= x_line.fi.fi && x_line.se.fi <= y_line.se.fi) {
        if (x_line.fi.se <= y_line.fi.se && y_line.se.se <= x_line.se.se) {
            return { x_line.fi.fi,y_line.fi.se };
        }
    }
    return { -1,-1 };
}

void setting_x(int2_int2 x_line) {
    unordered_set<intint, pair_hash>arr;
    intint last_p = x_line.fi;
    arr.insert(last_p);
    state[last_p].p = last_p;
    for (auto y_line : pin_y) {
        intint p = line_cross(x_line, y_line);
        if (p.fi == -1)continue;
        if (arr.find(p) != arr.end())continue;
        arr.insert(p);

        //cout << last_p.fi << "," << last_p.se << " <=> " << p.fi << "," << p.se << " 연결1.\n";
        state[last_p].down_Node = &state[p];
        state[p].up_Node = &state[last_p];

        last_p = p;
        state[last_p].p = last_p;
    }
}

void setting_y(int2_int2 y_line) {
    unordered_set<intint, pair_hash>arr;
    intint last_p = y_line.fi;
    arr.insert(last_p);
    state[last_p].p = last_p;
    for (auto x_line : pin_x) {
        intint p = line_cross(x_line, y_line);
        if (p.fi == -1)continue;
        if (arr.find(p) != arr.end())continue;
        arr.insert(p);

        //cout << last_p.fi << "," << last_p.se << " <=> " << p.fi << "," << p.se << " 연결2.\n";
        state[last_p].right_Node = &state[p];
        state[p].left_Node = &state[last_p];

        last_p = p;
        state[last_p].p = last_p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    intint f,lp, p;
    cin >> lp.fi >> lp.se;
    f = lp;
    for (int i = 1; i < n; i++) {
        cin >> p.fi >> p.se;
        if (lp.fi == p.fi)pin_x.push_back({ lp,p });
        else pin_y.push_back({ lp,p });
        lp = p;
    }

    if (lp.fi == f.fi)pin_x.push_back({ lp,f });
    else pin_y.push_back({ lp,f });

    sort(pin_x.begin(), pin_x.end(), x_sort);
    sort(pin_y.begin(), pin_y.end(), y_sort);

    for (int2_int2& h : pin_x) {
        if (h.fi.se > h.se.se)swap(h.fi.se, h.se.se);
    }

    for (int2_int2& h : pin_y) {
        if (h.fi.fi > h.se.fi)swap(h.fi.fi, h.se.fi);
    }

    for (auto h : pin_x) {
        setting_x(h);
    }

    for (auto h : pin_y) {
        setting_y(h);
    }

    int ans = 0;
    for (auto h : state) {
        //cout << h.fi.fi << "," << h.fi.se << "입장.\n";
        Node& check = h.se;
        if (check.right_Node == nullptr)continue;
        //cout << "1 통과.\n";
        check = *check.right_Node;
        if (check.down_Node == nullptr)continue;

        //cout << "2 통과.\n";
        check = *check.down_Node;
        if (check.left_Node == nullptr)continue;

        //cout << "3 통과.\n";
        check = *check.left_Node;
        if (check.up_Node == nullptr)continue;

        //cout << "4 통과.\n";
        check = *check.up_Node;
        //cout << check.p.fi << "," << check.p.se << " vs " << h.fi.fi << "," << h.fi.se << "\n";
        if (check.p == h.fi)ans++;
    }
    cout << ans;
}